CREATE  TABLE `skilltrees`.`nodes` (
  `idnodes` INT NOT NULL ,
  `nodename` VARCHAR(45) NULL ,
  `nodedesc` VARCHAR(45) NULL ,
  PRIMARY KEY (`idnodes`) )
ENGINE = MyISAM
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_general_ci
COMMENT = 'nodes info.';