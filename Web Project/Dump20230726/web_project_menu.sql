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
-- Table structure for table `menu`
--

DROP TABLE IF EXISTS `menu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `menu` (
  `pizza_id` int NOT NULL AUTO_INCREMENT,
  `pizza_name` varchar(45) NOT NULL,
  `ingredients` varchar(250) NOT NULL,
  `discount` int DEFAULT '0',
  `path` varchar(45) NOT NULL,
  PRIMARY KEY (`pizza_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `menu`
--

LOCK TABLES `menu` WRITE;
/*!40000 ALTER TABLE `menu` DISABLE KEYS */;
INSERT INTO `menu` VALUES (1,'Margherita Pizza','Tomato sauce, mozzarella cheese, fresh basil leaves, olive oil',20,'static/1.jpg'),(2,'Pepperoni Pizza','Tomato sauce, mozzarella cheese, pepperoni slices',0,'static/2.jpg'),(3,'Hawaiian Pizza','Tomato sauce, mozzarella cheese, ham slices, pineapple chunks',0,'static/3.png'),(4,'BBQ Chicken Pizza','BBQ sauce, mozzarella cheese, cooked chicken, red onions, cilantro',0,'static/4.png'),(5,'Veggie Supreme Pizza','Tomato sauce, mozzarella cheese, bell peppers, mushrooms, onions, olives',0,'static/5.png'),(6,'Meat Lover\'s Pizza','Tomato sauce, mozzarella cheese, pepperoni, sausage, bacon, ham',0,'static/6.png'),(7,'Four Cheese Pizza',' Tomato sauce, mozzarella cheese, cheddar cheese, Parmesan cheese, Gouda cheese',0,'static/7.png'),(8,'Margherita with Prosciutto','Tomato sauce, mozzarella cheese, fresh basil leaves, prosciutto, olive oil',0,'static/8.png'),(9,'Mediterranean Pizza',' Tomato sauce, mozzarella cheese, feta cheese, black olives, sun-dried tomatoes, fresh spinach',0,'static/9.png'),(10,'Chicken Alfredo Pizza','Alfredo sauce, mozzarella cheese, cooked chicken, mushrooms, garlic',0,'static/12.png'),(11,'Spinach and Feta Pizza','Alfredo sauce, mozzarella cheese, cooked chicken, mushrooms, garlic',0,'static/10.png');
/*!40000 ALTER TABLE `menu` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-07-26 17:41:51
