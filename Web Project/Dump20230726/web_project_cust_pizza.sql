-- MySQL dump 10.13  Distrib 8.0.27, for macos11 (x86_64)
--
-- Host: 127.0.0.1    Database: web_project
-- ------------------------------------------------------
-- Server version	8.0.33

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `cust_pizza`
--

DROP TABLE IF EXISTS `cust_pizza`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cust_pizza` (
  `id` int NOT NULL AUTO_INCREMENT,
  `cust_id` int DEFAULT NULL,
  `pizza_name` varchar(255) DEFAULT NULL,
  `size` varchar(50) DEFAULT NULL,
  `price` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `cust_pizza_ibfk_1_idx` (`cust_id`),
  KEY `cust_pizza_ibfk_11_idx` (`cust_id`),
  CONSTRAINT `cust_ids` FOREIGN KEY (`cust_id`) REFERENCES `customer` (`cust_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=96 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cust_pizza`
--

LOCK TABLES `cust_pizza` WRITE;
/*!40000 ALTER TABLE `cust_pizza` DISABLE KEYS */;
INSERT INTO `cust_pizza` VALUES (2,2,'Meat Lover\'s Pizza','medium',1200.00),(3,2,'Mediterranean Pizza','medium',1050.00),(4,2,'Mediterranean Pizza','large',1600.00),(5,2,'Margherita with Prosciutto','medium',1100.00),(6,2,'Customizable pizza ','small',900.00),(7,4,'Margherita Pizza','small',450.00),(8,4,'Pepperoni Pizza','small',560.00),(9,4,'Hawaiian Pizza','small',700.00),(10,4,'BBQ Chicken Pizza','small',550.00),(11,4,'BBQ Chicken Pizza','small',550.00),(12,4,'BBQ Chicken Pizza','small',550.00),(13,4,'BBQ Chicken Pizza','small',550.00),(14,4,'BBQ Chicken Pizza','small',550.00),(15,4,'BBQ Chicken Pizza','small',550.00),(16,4,'BBQ Chicken Pizza','small',550.00),(17,4,'BBQ Chicken Pizza','small',550.00),(18,4,'BBQ Chicken Pizza','small',550.00),(19,4,'BBQ Chicken Pizza','small',550.00),(20,4,'Veggie Supreme Pizza','small',460.00),(21,4,'Meat Lover\'s Pizza','small',450.00),(22,4,'Four Cheese Pizza','small',500.00),(23,4,'Margherita with Prosciutto','small',550.00),(24,4,'Mediterranean Pizza','small',500.00),(25,4,'Customizable pizza ','small',900.00),(26,5,'Margherita Pizza','small',450.00),(27,5,'Pepperoni Pizza','small',560.00),(28,5,'Hawaiian Pizza','small',700.00),(29,5,'BBQ Chicken Pizza','small',550.00),(30,5,'BBQ Chicken Pizza','small',550.00),(31,5,'BBQ Chicken Pizza','small',550.00),(32,5,'BBQ Chicken Pizza','small',550.00),(33,5,'BBQ Chicken Pizza','small',550.00),(34,5,'BBQ Chicken Pizza','small',550.00),(35,5,'BBQ Chicken Pizza','small',550.00),(36,5,'BBQ Chicken Pizza','small',550.00),(37,5,'BBQ Chicken Pizza','small',550.00),(38,5,'BBQ Chicken Pizza','small',550.00),(39,5,'Veggie Supreme Pizza','small',460.00),(40,5,'Meat Lover\'s Pizza','small',450.00),(41,5,'Four Cheese Pizza','small',500.00),(42,5,'Margherita with Prosciutto','small',550.00),(43,5,'Mediterranean Pizza','small',500.00),(44,5,'Customizable pizza ','small',900.00),(45,8,'Mediterranean Pizza','small',500.00),(46,8,'Customizable pizza ','small',900.00),(47,10,'Customizable pizza ','small',900.00),(48,10,'Four Cheese Pizza','small',500.00),(49,11,'Customizable pizza ','small',900.00),(50,11,'Pepperoni Pizza','large',1800.00),(51,11,'Chicken Alfredo Pizza','large',1550.00),(52,12,'Meat Lover\'s Pizza','large',1500.00),(53,12,'Margherita with Prosciutto','large',1550.00),(54,12,'Spinach and Feta Pizza','large',2000.00),(55,13,'Hawaiian Pizza','large',2000.00),(56,13,'Customizable pizza ','small',900.00),(57,14,'Pepperoni Pizza','large',1800.00),(58,15,'Chicken Alfredo Pizza','large',1550.00),(59,15,'Spinach and Feta Pizza','large',2000.00),(60,16,'Pepperoni Pizza','large',1800.00),(61,16,'Four Cheese Pizza','large',1600.00),(62,16,'Chicken Alfredo Pizza','large',1550.00),(63,17,'Pepperoni Pizza','small',560.00),(64,18,'Chicken Alfredo Pizza','small',580.00),(65,18,'Pepperoni Pizza','large',1800.00),(66,19,'Pepperoni Pizza','large',1800.00),(67,20,'Spinach and Feta Pizza','large',2000.00),(68,21,'Pepperoni Pizza','small',560.00),(69,22,'Spinach and Feta Pizza','large',2000.00),(70,23,'Customizable pizza ','small',900.00),(71,23,'Customizable pizza ','small',900.00),(72,24,'Spinach and Feta Pizza','small',600.00),(73,25,'Spinach and Feta Pizza','small',600.00),(74,27,'Meat Lover\'s Pizza','large',1500.00),(75,27,'Chicken Alfredo Pizza','large',1550.00),(76,27,'Spinach and Feta Pizza','large',2000.00),(77,27,'Chicken Alfredo Pizza','large',1550.00),(78,27,'Spinach and Feta Pizza','large',2000.00),(79,28,'Chicken Alfredo Pizza','large',1550.00),(80,28,'Spinach and Feta Pizza','large',2000.00),(81,29,'Chicken Alfredo Pizza','large',1550.00),(82,29,'Spinach and Feta Pizza','large',2000.00),(83,29,'Chicken Alfredo Pizza','large',1550.00),(84,30,'Meat Lover\'s Pizza','large',1500.00),(85,31,'Chicken Alfredo Pizza','large',1550.00),(86,32,'Chicken Alfredo Pizza','large',1550.00),(87,33,'Chicken Alfredo Pizza','large',1550.00),(88,35,'Chicken Alfredo Pizza','large',1550.00),(89,36,'Mediterranean Pizza','large',1600.00),(90,37,'Chicken Alfredo Pizza','large',1550.00),(91,38,'Pepperoni Pizza','large',1800.00),(92,38,'Meat Lover\'s Pizza','large',1500.00),(93,39,'Meat Lover\'s Pizza','large',1500.00),(94,39,'Spinach and Feta Pizza','small',600.00),(95,39,'Spinach and Feta Pizza','small',600.00);
/*!40000 ALTER TABLE `cust_pizza` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-07-26 17:41:52
