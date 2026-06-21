# Customer-Relationship-Management-with-C

## Introduction
This CRM system is built using C language to store records of the customers. It uses the concept of structure and file handling. It provides various functionalities such as add, display, and search records of the customers, and display total and average amount spent by a customer. 

## Functionalities
- **Add customer records:** It takes input data from the user such as customer name, products purchased, price of each product,   and feedback and stores the data in “customer.txt” file.

- **Display customer records:** It displays all the records stored in “customer.txt” in order of the highest purchase amount. 

- **Search records of a customer:** It allows the users to search for the records of a customer stored in “customer.txt” file. If the name inserted by the user is present in the file, the records are displayed to the user. But, if the name inserted by the user is not present in the file, a message i.e., “Record is not present” is displayed on the screen. 

- **Total purchase amount and average amount of a customer:** It displays the total purchase amount and the average amount spent by a customer.

## Code Explanation

**1.	Including libraries:**
This program includes two libraries:\
i.	stdio.h: It provides variety of functions for input/output operations such as printf, scanf, fprintf, etc.\
ii.	string.h: It provides a set of functions for manipulating strings such as strcmp, strlen, strcpy, etc.
	
**2.	Defining structure:**
“struct customer” defines a structure named “customer” which groups related data items of different data types into a single unit. Each data item is called member of structure. The different members of structure customer are given below:\
i.	char n[35]: It defines a character array named “n” which can store up to 35 characters. It is used to store the customer’s name.\
ii.	int a: It defines an integer variable named “a” which is used to store the number of products purchased by a customer.\
iii.	char pn[50][50]: It defines a two-dimensional character array named “pn” which is used to store the names of the products purchased by the customer. It allows the user to store up to 50 product names, each with a name up to 50 characters.\
iv.	float p[50]: It defines a floating-point array named “p” with a length 50. It is used to store the price of each product purchased by the customer.\
v.	char fb[150]: It defines a character array of length 150 to store feedback provided by the customer.\
vi.	float total_purchase: It defines a floating-point variable named total_purchase which is used to store the total purchase amount of the customer.

**3.	Sorting customer records:**
The purpose of this function is to compare and swap customer records if the total purchase amount of one customer is less than that of another. i and j are two loop variables and temp is a temporary variable of struct customer which is used for swapping. The if statement compares the total purchase amount of the selected customer (c[i]) with the total purchase amounts of remaining customers (c[j]). If the total purchase amount of c[i] is less than that of c[j], the records are swapped to arrange them in descending order. 

**4.	Adding customer records:**
The “customer.txt” file is opened in append mode, allowing users to insert records into the file. Structure of array is used to allow the users to insert n number of customers. It takes input from the user in the first for loop and stores the input in “customer.txt” in the second for loop. It calculates the total purchase amount for each customer and calls the function sort_customers which compares and swaps customer records if the total purchase amount of one customer is less than that of another. This ensures that the records of the customer with higher purchase amount are displayed first. After the records are successfully stored, it asks the user if they want to add more records. The do loop continues if the user wants to add more records otherwise the loop terminates. 

**5.	Displaying customer records:**
It opens the file in read mode. The while (fgets(line, sizeof(line), fp)) loop is used to read each line from the file and store it in character array line until the end of the file is reached. It reads and displays each line of the file i.e. all the records present in “customer.txt” file. 

**6.	Searching records of a customer:**
It opens “customer.txt” file in read mode. It asks the user to insert the name of the customer they want to search. The while loop reads each line from the file and stores it in character array line until fgets returns NULL.\
Inside the while loop, “strstr(line, "Customer Name:") != NULL” checks if the substring “Customer Name:” is present within the line of string and “strstr(line, sn) != NULL” checks if the substring “sn” (the name inserted by the user) is present within the same line of string. If the name inserted by the user is present in the file, found is set to 1 indicating that the customer has been found and the line containing the substrings gets printed.\
Another while loop prints the remaining details of the customer until another line containing substring “Customer Name:” is encountered. However, if the name inserted by the user is not present in the file, a message i.e., “Record is not present” is displayed on the screen.

**7.	Displaying total purchase amount and average amount of a customer:**
It opens “customer.txt” file in read mode. It asks the user to insert the name of the customer whose total and average purchase amount they want to search. The while loop reads each line from the file and stores it in character array line until fgets returns NULL.  
Inside the while loop, “strstr(line, "Customer Name:") != NULL” checks if the substring “Customer Name:” is present within the line of string and “strstr(line, cn) != NULL” checks if the substring “cn” (the name inserted by the user) is present within the same line of string. If the conditions are satisfied, found is set to 1 indicating that the customer has been found.  
Another while loop reads the remaining lines until another “Customer Name:” is encountered. It processes each line to extract product information (S.N., product name and price) using sscanf and performs the operations for tp and c. After reading all the products, the average amount is calculated and both the total and the average amounts are printed. 
