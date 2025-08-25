# CS-210---Programming-Languages

**Project Three: Corner Grocer Item-Tracking Application**  
>This repository contains the C++ source files for the Corner Grocer project. This program is a console application designed to analyze daily purchase records from a text file, calculate the frequency of each item sold, and present this data to the user in various formats.

**Project Reflection**

**Summarize the project and what problem it was solving.**  
>This C++ console application solves a data analysis problem for a grocery store. It automates the process of understanding customer purchasing habits by reading a file of daily sales, calculating item purchase frequencies, and displaying the data through a user menu with multiple views (single item, full list, and histogram).

**What did you do particularly well?**  
>The use of the std::map data structure was a key success, as it efficiently handled the logic of tracking and counting unique items. Additionally, the object-oriented design, centered on the CornerGrocer class, resulted in clean, organized, and easy-to-follow code.

**Where could you enhance your code?**  
>Future enhancements could include more graceful error handling for missing files (prompting the user for a new path instead of exiting), implementing case-insensitive searching for a better user experience, and developing a graphical user interface (GUI) for improved accessibility.

**Which pieces of the code did you find most challenging to write, and how did you overcome this?**  
>The most challenging aspect was correctly implementing file input/output, specifically writing the backup file at the start of the program. I overcame this by consulting official C++ documentation and reviewing course examples, which are now key resources in my support network.

**What skills from this project will be particularly transferable?**  
>This project solidified highly transferable skills in Object-Oriented Programming (OOP), using C++ Standard Template Library (STL) containers like std::map, performing file I/O, and implementing user input validation—all fundamental concepts in software development.

**How did you make this program maintainable, readable, and adaptable?**  
>The program's quality was ensured through several practices. Readability was achieved with clear naming conventions and extensive comments. Maintainability comes from the modular, class-based structure that isolates functionality. Finally, its adaptability is demonstrated by the ability to change the input file in the main function without altering the core logic.
