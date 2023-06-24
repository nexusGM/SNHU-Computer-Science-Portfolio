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

##### Project Summary and Problem Solved

- The Gaming Room is a client that hired us, Creative Technology Solutions (CTS), to develop a web-based version of their game, Draw It or Lose It. This game is a drawing and guessing game that allows users to create and join teams and compete against each other. The game should support multiple platforms, such as Windows, Linux, and Mac OS, and have unique identifiers for each game, team, and player. The game should also have a distributed architecture that allows users to communicate and interact with each other across different networks.

- To design the software for this game, I used the Unified Modeling Language (UML) class diagram to represent the domain model of the game application. I also used object-oriented programming principles to create classes that encapsulate the attributes and behaviors of the game entities. Furthermore, I used design patterns to implement the singleton pattern for the game class, the factory method pattern for the team class, and the prototype pattern for the player class.

- In this document, I will explain the operating system architectures for different operating systems that the game will run on. I will also analyze the differential file system components that represent a collection of data for the game. Moreover, I will explain the functions of memory and storage management for the game application. I will also identify memory management techniques that optimize the performance and reliability of the game. Finally, I will describe distributed systems and the networks that interconnect them for the game communication and interaction.

##### Developing documentation 

- In developing the documentation, I ensured that it was comprehensive, well-organized, and easy to understand. I included step-by-step instructions, clear explanations, and relevant examples to guide users through the software's features and functionality. I also made sure to document any assumptions or limitations of the software to set clear expectations for users.

- The design document served as a roadmap for the development process. It outlined the software's architecture, modules, data flow, and interfaces, which helped the development team understand the system's structure and functionality. It also facilitated communication among team members, ensured consistency in coding standards, and helped in identifying potential issues early in the development process.

- If I were to revise a part of my work on the documents, I would focus on improving the clarity and conciseness of the instructions. I would also ensure that all relevant information, such as installation steps, configuration settings, and troubleshooting tips, are included. Additionally, I would consider incorporating visual aids, such as diagrams or screenshots, to further enhance understanding.

- To interpret user needs I reviewed the current code provided and reviewed and researched the software requirements provided. If I were to do this project with real people I would have conducted thorough research, including user surveys, interviews, and usability testing. I would also have considered feedback from stakeholders to understand their requirements and preferences. Based on this information, I incorporated features and functionality into the software design that aligned with the users' needs, ensuring that the software provided a solution to their specific problems.

- I followed a systematic approach to software design, including defining the problem statement, identifying requirements, creating a high-level architecture, and breaking it down into smaller components. I also utilized techniques such as UML diagrams, flowcharts, and pseudocode to visualize the design and ensure that it met the requirements.

---

### CS-320 Software Test Automation & QA
#### Testing Using JUnit

##### Code That is Functional and Secure

- To ensure that my code, program, or software is functional and secure, I can use various testing techniques such as unit testing, integration testing, system testing, and security testing. I can also use tools such as code analyzers, debuggers, and code coverage tools to identify and fix errors, vulnerabilities, and bugs in my code. I can also follow coding standards and best practices to write clean, maintainable, and secure code.

##### Interpreting User Needs and Integrating Them

- To interpret user needs and incorporate them into a program, I can use methods such as requirements analysis, user stories, use cases, and scenarios. I can also communicate with the users and stakeholders to elicit their feedback and expectations. I can also use prototyping and user testing to validate and refine my design and implementation.

##### The Approach to Design

- To approach designing software, I can use various software engineering models and methodologies such as waterfall, agile, or spiral. I can also use design principles and patterns to create a modular, reusable, and scalable architecture. I can also use diagrams and documentation to communicate and document my design decisions and rationale.

---

### CS-255 System Analysis and Design
#### Testing Using JUnit

##### Project Summary and Problem Solved

- The DriverPass project involved designing a system for a client called DriverPass. They wanted a system to facilitate the reservation and management of driving test appointments. I successfully created various UML diagrams, including use case, activity, sequence, and class diagrams, to represent the system's functionalities and structure.

##### Potential Revisions

- If I had to revise one part of my work, I would focus on improving the clarity and completeness of the system requirements. Providing more detailed and explicit requirements would enhance the accuracy and effectiveness of the system design.

##### Interpreting User Needs

- To interpret the user's needs, I thoroughly analyzed the client's business requirements document and actively communicated with stakeholders to gather additional information. I then translated those needs into concrete system features and incorporated them into the UML diagrams. Considering the user's needs is crucial because it ensures that the system is designed to fulfill their requirements and provides a positive user experience.

##### The Approach

- When approaching software design, I follow a systematic approach that includes understanding the problem domain, conducting thorough analysis, and utilizing appropriate design principles and techniques. In the future, I would continue to leverage techniques such as requirement gathering, prototyping, iterative design, and user feedback to refine and optimize the system design. Additionally, employing agile methodologies and collaborating closely with stakeholders and developers would contribute to a successful system design process.
