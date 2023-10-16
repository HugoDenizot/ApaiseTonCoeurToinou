package isima.F2.TP3.BALLEJOSDENIZOT;

import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.io.Console;

import static org.apache.commons.lang3.StringUtils.reverse;

@SpringBootApplication
public class Application {

	private static final Logger logger = LoggerFactory.getLogger(Application.class);

	public static void main(String[] args) {
		SpringApplication.run(Application.class, args);
		logger.warn("Hello Word");
		logger.debug("Reverse en Debug: " + reverse("BALLEJOS DENIZOT"));
	}

}
