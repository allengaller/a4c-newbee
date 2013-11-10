<?
/*
工厂模式

工厂模式（Factory）允许你在代码执行时实例化对象。它之所以被称为工厂模式是因为它负责“生产”对象。工厂方法的参数是你要生成的对象对应的类名称。  
*/
class Example {
	//The parameterized factory method
	public static function factory($type) {
		if(include_once 'Drivers/' .$type. '.php') {
			$classname = 'Driver_' . $type;
			return new $classname;
		} else {
			throw new Exception ('Driver not found!');
		}
	}
}

//Load a MySQL Driver
$mysql = Example::factory('MySQL');
//Load a SQLite Driver
$sqlite = Example::factory('SQLite');

/*
单例

单例模式（Singleton）用于为一个类生成一个唯一的对象。最常用的地方是数据库连接。  使用单例模式生成一个对象后，该对象可以被其它众多对象所使用。 
*/

class Example {
	//保存类实例在此属性中
	private static $instance;

	//构造方法声明为private，防止直接创建对象
	private function __construct() {
		echo 'I am constructed!';
	}

	//singleton method
	public static function singleton() {
		if(!isset(self::$instance)) {
			$c = __CLASS__;
			self::$instance = new $c;
		}

		return self::$instance;
	}

	//normal method in Example class
	public function bark() {
		echo 'Woof!';
	}

	//阻止用户复制对象实例
	public function __clone() {
		trigger_error('Clone is not allowed!', E_USER_ERROR);

	}
}

// 这个写法会出错，因为构造方法被声明为private
$test = new Example;
// 下面将得到Example类的单例对象
$test = Example::singleton();
$test->bark();
// 复制对象将导致一个E_USER_ERROR.
$test_clone = clone $test;
