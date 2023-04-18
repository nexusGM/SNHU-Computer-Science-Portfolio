package com.snhu.sslserver;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.http.MediaType;
import org.springframework.util.DigestUtils;

@SpringBootApplication
@RestController
public class SslServerApplication {

	public static void main(String[] args) {
		SpringApplication.run(SslServerApplication.class, args);
	}
	//FIXME: Add route to enable check sum return of static data example:  String data = "Hello World Check Sum!";
	@GetMapping(value = "/checksum", produces = MediaType.TEXT_PLAIN_VALUE)
	public String getChecksum() {
		String data = "Hello World Check Sum!";
		String checksum = DigestUtils.md5DigestAsHex(data.getBytes());
		return "The check sum of " + data + " is " + checksum;
	}
}
