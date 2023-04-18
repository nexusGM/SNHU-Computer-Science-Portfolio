# SNHU Computer Science Portfolio
## Matthew Tyson

---

### CS-250 Software Developement Lifecycle
#### Sprint Review and Retrospective

- How do I interpret user needs and implement them into a program? How does creating “user stories” help with this?
  - To interpret user needs and implement them into a program, it is essential to engage in effective communication with the user, understand their requirements, and develop a deep understanding of their goals and objectives. It is important to ask questions, clarify expectations, and document feedback to ensure that the final product meets the user's needs. Creating user stories is a powerful tool in this regard, as it helps to identify the key requirements of the user and develop a clear understanding of what the software should do and how it should function. User stories provide a structured approach to understanding user needs and incorporating them into the software development process.

- How do I approach developing programs? What agile processes do I hope to incorporate into my future development work?
  - Approaching program development requires a structured and iterative approach that involves multiple stages of planning, design, testing, and deployment. It is important to gather requirements, create a clear plan, develop a design that meets those requirements, test the program, and then deploy it to users. Agile processes are an effective way to approach program development, as they prioritize flexibility and collaboration, emphasize iterative development, and encourage frequent communication and feedback between developers and users. Agile processes like Scrum, Kanban, and XP can all help ensure that the development process is flexible, efficient, and effective.

- What does it mean to be a good team member in software development?
  - Being a good team member in software development involves many different qualities and skills. Effective communication, collaboration, and problem-solving are all critical aspects of being a good team member. It is important to be open to feedback, work well with others, and take a proactive approach to resolving issues and addressing challenges. Good team members are also committed to quality, take pride in their work, and have a strong work ethic. Ultimately, being a good team member in software development means being committed to the success of the project and working collaboratively with others to achieve that success.

---

### CS-210 Programming Languages
#### Corner Grocer Item-Tracking Program

##### Project Summary and Problem Solved

- The project is to build an item-tracking program for the Corner Grocer, which analyzes text records generated throughout the day, listing items purchased in chronological order from the time the store opens to the time it closes. The program must incorporate the requested functionality of providing the frequency of specific items, a list of all items with their frequency, a histogram showing the frequency of each item, and the ability to create a backup file with the accumulated data.

- The Corner Grocer needed a program to help them rearrange their produce section by identifying how often items were purchased. This program solves that problem by analyzing the text records generated throughout the day and providing the frequency of each item purchased.

##### What was done particularly well

- The use of classes with public and private sections.
- Implementation of maps to store and retrieve data.

##### Areas for Improvement

- The code could be enhanced by adding input validation and error handling to anticipate, detect, and respond to run-time and user errors.
- The code could be made more efficient by optimizing data structures and algorithms.

##### Challenges and Solutions

- The implementation of the histogram was a challenging piece of code.

- The challenges were overcome by researching and experimenting with different approaches until an efficient and effective solution was found.
  
- Various resources and tools, such as zyBooks and Visual Studio 2019, were used to support the development of the program.
  
##### Transferable Skills

- Writing professional, well-documented, and readable code
- Utilizing various programming languages to develop secure, efficient code
- Implementing classes and maps.

##### Maintainability, Readability, and Adaptability

- Industry-standard best practices were applied, such as using appropriate naming conventions and in-line comments to enhance readability and maintainability. The code was also designed to be adaptable by utilizing classes and maps, which allow for easy modification and expansion.

---

### CS-305 Software Security
#### Practices for Secure Software and Vulnerability Assessment Reports

##### Project Summary and Problem Solved

- Artemis Financial was my client, and they approached me to conduct a vulnerability assessment of their financial software application. The client wanted me to identify and address any security vulnerabilities in the code to ensure the software's security and protect sensitive financial data.

- During the vulnerability assessment, I conducted thorough code review and penetration testing to identify security vulnerabilities such as SQL injection, cross-site scripting (XSS), and authentication issues. I also analyzed the software's architecture and design to identify potential vulnerabilities. I utilized various security tools and techniques to identify and verify vulnerabilities and provided recommendations for their mitigation.

- It is important to code securely because software vulnerabilities can be exploited by malicious actors to gain unauthorized access, steal sensitive data, or disrupt business operations. By addressing these vulnerabilities, software security adds value to a company's overall well-being by protecting its reputation, ensuring customer trust, and preventing financial and legal liabilities.

##### Challenges

- The most challenging part of the vulnerability assessment was to prioritize the risks and decide which ones to address first. I used the OWASP risk rating methodology to evaluate the likelihood and impact of each vulnerability and rank them accordingly. The most helpful part of the vulnerability assessment was to use the OWASP top 10 list as a reference for common web application security flaws and how to prevent them.

##### Increasing Layers of Security

- I increased layers of security by implementing a checksum mechanism for file verification. A checksum is a mathematical value that is calculated from the data in a file and can be used to detect any changes or errors in the file. I used a secure hash algorithm (SHA-256) to generate the checksums for both the sender and the receiver of the data. The sender would calculate the checksum of the file before sending it and include it in the message. The receiver would calculate the checksum of the file after receiving it and compare it with the one sent by the sender. If they match, then the file is verified; if not, then there is a problem with the file or the communication.

- I made sure that the code and software application were functional and secure by testing them thoroughly. I used unit testing, integration testing, system testing, and acceptance testing to check for functionality, performance, usability, reliability, and security. I also used code analysis tools and vulnerability scanners to check for any new vulnerabilities that I might have introduced after refactoring the code. I fixed any issues that I found and documented them accordingly.

##### Tools and Resources

- Some of the resources, tools, or coding practices that I used that might be helpful in future assignments or tasks are:
  - OWASP website: https://owasp.org/
  - Secure coding guidelines: https://www.securecoding.cert.org/
  - Code analysis tools: https://owasp.org/www-community/Source_Code_Analysis_Tools
  - Vulnerability scanners: https://owasp.org/www-community/Vulnerability_Scanning_Tools
  - Checksum calculators: https://www.fileformat.info/tool/hash.htm

##### Transferable Skills

- Conduct a thorough vulnerability assessment. 
- Identify and address software security vulnerabilities.
- Implement mitigation techniques. 
- Expertise in using various security tools.
- Follow coding best practices.
- Conduct rigorous testing to ensure functional and secure code.

---

### CS-230 Operating Platforms
#### Software Design Document
