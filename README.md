All these files are written by me except "tm4c123gh6pm.h" which defines all registers. Without including it, you will have to open datasheet and deal with base and offset addresses for all registers, so for using drivers directly without any edition, please do not exclude it from any header file.

You do not have to open header files to understand how any function works and when to use it, you just need to read the description file for each module very carefully since I will explain each function clearly and the enumerations I have created since you will use some of them when you call some of my function in your main.

Note that you have to write interrupt service routines(interrupt handlers) by yourself in case that you use some of function that enable interrupts, but if you use some of my functions that do polling, you do not need to add anything.

Be very careful when using boolean functions ( functions start with "is" ) since they return 3 values not only two:
1) one when the condition you check occured and your arguments are valid
2) zero when the condition you check did not occur and your arguments are valid
3) another value if your arguments are inavlid

