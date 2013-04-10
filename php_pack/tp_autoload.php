<?
//1、在common/functions.php里面：

function__autoload($name) {

    return Think::autoload($name);

}


// 优化的require_once,将一些要包含的文件 放在静态数组里面，当再次加入的时候，判断是否已经存在了

function require_cache($filename) {

    static $_importFiles= array();          //设置了所有引入过得文件的标示$_importFiles[$filename]，引入一个就设置一个标示

    $filename = realpath($filename);

    if (!isset($_importFiles[$filename])) {

        if (file_exists_case($filename)) {

            require $filename;

            $_importFiles[$filename] = true;

        } else {

            $_importFiles[$filename] = false;

        }

    }

    return $_importFiles[$filename];

}

// 区分大小写的文件存在判断

function file_exists_case($filename) {

    if (is_file($filename)) {

        if (IS_WIN && C('APP_FILE_CASE')) {

            if (basename(realpath($filename)) != basename($filename))

                return false;

        }

        return true;

    }

    return false;

}



2、在Lib/Think/Core/Think.class.php

define('LIB_DIR',      'Lib');

APP_PATH  会在你的入口文件如index.php里面或者admin.php里面定义~~当然这个入口文件随便你自己命名

/**

     +----------------------------------------------------------

     * 系统自动加载ThinkPHP类库

     * 并且支持配置自动加载路径

     +----------------------------------------------------------

     * @param string $classname 对象类名

     +----------------------------------------------------------

     * @return void

     +----------------------------------------------------------

     */

    public static function autoload($classname){

        // 检查是否存在别名定义

        if(alias_import($classname)) return ;

        // 自动加载当前项目的Action类和Model类

        if(substr($classname,-5)=="Model") {

           require_cache(LIB_PATH.'Model/'.$classname.'.class.php');

        }elseif(substr($classname,-6)=="Action"){

            require_cache(LIB_PATH.'Action/'.$classname.'.class.php');       // define('LIB_PATH',  APP_PATH.'/'.LIB_DIR.'/'); 

        }else {

            // 根据自动加载路径设置进行尝试搜索

            if(C('APP_AUTOLOAD_PATH')) {

                $paths  =   explode(',',C('APP_AUTOLOAD_PATH'));  //在用户自定义的model和action找不到的时候，就去搜索系统配置的

                foreach ($paths as $path){

                    if(import($path.$classname))

                        // 如果加载类成功则返回

                        return ;

                }

            }

        }

        return ;

    }


// 快速定义和导入别名

functionalias_import($alias, $classfile='') {

    static $_alias = array();

    if ('' !== $classfile) {

        // 定义别名导入

        $_alias[$alias] = $classfile;

        return;

    }

    if (is_string($alias)) {

        if (isset($_alias[$alias]))

            return require_cache($_alias[$alias]);

    }elseif (is_array($alias)) {

        foreach ($alias as $key => $val)

            $_alias[$key] = $val;

        return;

    }

    return false;

}


三、这里涉及到方法C(),这个方法在common/functions.php定义如下：

// 获取配置值

function C($name=null, $value=null) {

    static $_config = array();

    // 无参数时获取所有

    if (empty($name))

        return $_config;

    // 优先执行设置获取或赋值

    if (is_string($name)) {

        $name = strtolower($name);

        if (!strpos($name, '.')) {

            if (is_null($value))

                return isset($_config[$name]) ? $_config[$name] : null;

            $_config[$name] = is_array($value)?array_change_key_case($value):$value;

            return;

        }

        // 二维数组设置和获取支持

        $name = explode('.', $name);

        if (is_null($value))

            return isset($_config[$name[0]][$name[1]]) ? $_config[$name[0]][$name[1]] : null;

        $_config[$name[0]][$name[1]] = $value;

        return;

    }

    // 批量设置

    if (is_array($name)){

        foreach ($name as $key=>$val){

            if(is_array($val)) {

                $name[$key]  =  array_change_key_case($val);

            }

        }

        return $_config = array_merge($_config, array_change_key_case($name));

    }

    return null; // 避免非法参数

}


