CREATE TABLE IF NOT EXISTS `users` (
  `user_id` INT NOT NULL AUTO_INCREMENT,
  `login` VARCHAR(255) NOT NULL,
  `email` VARCHAR(255) NOT NULL,
  `first_name` VARCHAR(255),
  `last_name` VARCHAR(255),
  `birthday` DATE,
  `registration_dttm` TIMESTAMP NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `email_UNIQUE` UNIQUE(`email`)
);

CREATE TABLE IF NOT EXISTS `serial_studios` (
  `studio_id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NOT NULL,
  `foundation_date` DATE NOT NULL,
  `president_name` VARCHAR(45),
  PRIMARY KEY (`studio_id`)
);

CREATE TABLE IF NOT EXISTS `serials` (
  `serial_id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL,
  `genre` VARCHAR(255),
  `description` VARCHAR(255),
  `studio_id` INT NOT NULL,
  `format` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`serial_id`),
  FOREIGN KEY (`studio_id`)
    REFERENCES `serial_studios`(`studio_id`)
);

CREATE TABLE IF NOT EXISTS `series` (
  `series_id` INT NOT NULL AUTO_INCREMENT,
  `serial_id` INT NOT NULL,
  `season` INT,
  `name` VARCHAR(255) NOT NULL,
  `duration` TIME NOT NULL,
  `release_date` TIMESTAMP NOT NULL,
  PRIMARY KEY (`series_id`),
  FOREIGN KEY (`serial_id`)
    REFERENCES `serials`(`serial_id`)
);

CREATE TABLE IF NOT EXISTS `payments` (
  `payment_id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NOT NULL,
  `payment_dttm` TIMESTAMP NOT NULL,
  `payment_sum` DOUBLE NOT NULL,
  `paid_period_start` TIMESTAMP NOT NULL,
  `paid_period_end` TIMESTAMP NOT NULL,
  PRIMARY KEY (`payment_id`),
  FOREIGN KEY (`user_id`)
    REFERENCES `users` (`user_id`)
);

CREATE TABLE IF NOT EXISTS `views` (
  `view_id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NOT NULL,
  `series_id` INT NOT NULL,
  `rating` INT,
  `start_time` TIMESTAMP NOT NULL,
  `end_time` TIMESTAMP NOT NULL,
  PRIMARY KEY (`view_id`),
  FOREIGN KEY (`user_id`)
    REFERENCES `users` (`user_id`),
  FOREIGN KEY (`series_id`)
    REFERENCES `series` (`series_id`)
);

CREATE TABLE IF NOT EXISTS `actors` (
  `actor_id` INT NOT NULL AUTO_INCREMENT,
  `first_name` VARCHAR(255) NOT NULL,
  `last_name` VARCHAR(255) NOT NULL,
  `birthday` DATE NOT NULL,
  `gender` CHAR(1),
  PRIMARY KEY (`actor_id`)
);

CREATE TABLE IF NOT EXISTS `serials_has_actors` (
  `serial_id` INT NOT NULL,
  `actor_id` INT NOT NULL,
  PRIMARY KEY (`serial_id`, `actor_id`),
  FOREIGN KEY (`serial_id`)
    REFERENCES `serials` (`serial_id`),
  FOREIGN KEY (`actor_id`)
    REFERENCES `actors` (`actor_id`)
);
