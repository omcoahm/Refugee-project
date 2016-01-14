-- phpMyAdmin SQL Dump
-- version 4.3.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 13, 2016 at 06:19 PM
-- Server version: 5.6.24
-- PHP Version: 5.6.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `test`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE IF NOT EXISTS `admin` (
  `username` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`username`, `password`) VALUES
('administrator', 'administrator');

-- --------------------------------------------------------

--
-- Table structure for table `friends`
--

CREATE TABLE IF NOT EXISTS `friends` (
  `user` varchar(100) NOT NULL,
  `friendUser` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `textmessages`
--

CREATE TABLE IF NOT EXISTS `textmessages` (
  `id` int(11) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `content` varchar(1000) NOT NULL,
  `fromUser` varchar(100) NOT NULL,
  `toUser` varchar(100) NOT NULL,
  `timeSent` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id_number` int(11) NOT NULL,
  `name` varchar(20) NOT NULL,
  `old_address` varchar(100) NOT NULL,
  `new_address` varchar(100) NOT NULL,
  `old_city` varchar(50) NOT NULL,
  `new_city` varchar(50) NOT NULL,
  `old_country` varchar(50) NOT NULL,
  `new_country` varchar(50) NOT NULL,
  `phone_number` int(11) NOT NULL,
  `email` varchar(100) NOT NULL,
  `age` int(11) NOT NULL,
  `birth_date` varchar(25) NOT NULL,
  `mothers_name` varchar(20) NOT NULL,
  `fathers_name` varchar(20) NOT NULL,
  `second_name` varchar(50) NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `voicemessages`
--

CREATE TABLE IF NOT EXISTS `voicemessages` (
  `ID` int(11) NOT NULL,
  `timeSent` varchar(100) NOT NULL,
  `fromUser` varchar(100) NOT NULL,
  `toUser` varchar(100) NOT NULL,
  `title` varchar(100) NOT NULL,
  `path` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `textmessages`
--
ALTER TABLE `textmessages`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id_number`);

--
-- Indexes for table `voicemessages`
--
ALTER TABLE `voicemessages`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `textmessages`
--
ALTER TABLE `textmessages`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id_number` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `voicemessages`
--
ALTER TABLE `voicemessages`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
