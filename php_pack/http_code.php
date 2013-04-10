<?

//一、发送Http状态信息

function send_http_status($code) {

    static $_status = array(

        // Informational 1xx

        100 => 'Continue',

        101 => 'Switching Protocols',

        // Success 2xx

        200 => 'OK',

        201 => 'Created',

        202 => 'Accepted',

        203 => 'Non-Authoritative Information',

        204 => 'No Content',

        205 => 'Reset Content',

        206 => 'Partial Content',

        // Redirection 3xx

        300 => 'Multiple Choices',

        301 => 'Moved Permanently',

        302 => 'Moved Temporarily ',  // 1.1

        303 => 'See Other',

        304 => 'Not Modified',

        305 => 'Use Proxy',

        // 306 is deprecated but reserved

        307 => 'Temporary Redirect',

        // Client Error 4xx

        400 => 'Bad Request',

        401 => 'Unauthorized',

        402 => 'Payment Required',

        403 => 'Forbidden',

        404 => 'Not Found',

        405 => 'Method Not Allowed',

        406 => 'Not Acceptable',

        407 => 'Proxy Authentication Required',

        408 => 'Request Timeout',

        409 => 'Conflict',

        410 => 'Gone',

        411 => 'Length Required',

        412 => 'Precondition Failed',

        413 => 'Request Entity Too Large',

        414 => 'Request-URI Too Long',

        415 => 'Unsupported Media Type',

        416 => 'Requested Range Not Satisfiable',

        417 => 'Expectation Failed',

        // Server Error 5xx

        500 => 'Internal Server Error',

        501 => 'Not Implemented',

        502 => 'Bad Gateway',

        503 => 'Service Unavailable',

        504 => 'Gateway Timeout',

        505 => 'HTTP Version Not Supported',

        509 => 'Bandwidth Limit Exceeded'

    );

    if(array_key_exists($code,$_status)) {

        header('HTTP/1.1 '.$code.' '.$_status[$code]);

    }

}

//二、 thinkphp中common/functions.php里面，个人觉得这个方法不错~~

// 取得对象实例 支持调用类的静态方法

function get_instance_of($name, $method='', $args=array()) {

    static $_instance = array();   //保存着所有的静态对象

    $identify = empty($args) ? $name . $method : $name . $method . to_guid_string($args);         // $identify 是对应的标示，如果有参数，则加上参数的标示    


    if (!isset($_instance[$identify])) {

        if (class_exists($name)) {

            $o = new $name();

            if (method_exists($o, $method)) {

                if (!empty($args)) {

                    $_instance[$identify] = call_user_func_array(array(&$o, $method), $args);

                } else {

                    $_instance[$identify] = $o->$method();

                }

            }

            else

                $_instance[$identify] = $o;

        }

        else

            halt(L('_CLASS_NOT_EXIST_') . ':' . $name);

    }

    return $_instance[$identify];

}
