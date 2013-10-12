DROP TABLE IF EXISTS `posts`;
CREATE TABLE `posts` (
 `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
 `title` varchar(50) COLLATE utf8_general_ci,
 `body` text COLLATE utf8_general_ci,
 `created` datetime DEFAULT NULL,
 `modified` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

LOCK TABLES `posts` WRITE;
/*!40000 ALTER TABLE `posts` DISABLE KEYS */;
INSERT INTO `posts` VALUES (1,'The title','This is the post body.','2012-11-01 15:43:41',NULL),(2,'A title once again','And the post body follows.','2012-11-01 15:43:41',NULL),(3,'Title strikes back','This is really exciting! Not.','2012-11-01 15:43:41',NULL),(4,'ggjjkhkhhk','7777777777777777777777777\r\n777777777777777777777777','2012-11-01 20:16:28','2012-11-01 20:16:28');
/*!40000 ALTER TABLE `posts` ENABLE KEYS */;
UNLOCK TABLES;