<?
//定义一个抽象基类
abstract class Car {
	//任何基类方法
	abstract function getMaximumSpeed();
}

//继承抽象类
class FastCar extends Car {
	function getMaximumSpeed() {
		return 150;
	}
}

//使用抽象类提供的公共功能
class Street {
	protected $speedLimit;
	protected $cars;

	public function __construct($speedLimit = 200) {
		$this->cars = array(); //对变量进行初始化
		$this->speedLimit = $speedLimit;
	}

	protected function isStreetLegel($car) {
		if($car->getMaximumSpeed() < $this->speedLimit) {
			return true;
		} else {
			return false;
		}
	}

	public function addCar($car) {
		if($this->isStreetLegel($car)) {
			echo 'The Car was allowed on the road!';
			$this->cars[] = $car;
		} else {
			echo 'The car is too fast and was not allowed on the road!';
		}
	}
}

//使用抽象类
$street = new Street();
$street->addCar(new FastCar());