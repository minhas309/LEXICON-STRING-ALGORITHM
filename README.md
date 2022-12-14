# LEXICON-STRING-ALGORITHM
LEXICON ALGORITHM of strings through c++ 

Hash Table Organization: A lexicon of (English character) words. Do the programming related to 
the building of a Hash Table that can maintain arbitrarily long strings in C, C++, or Java. It is 
similar to that also used by Google around 1997-1998. The implementation should be optimized 
enough for a test execution to take no more than few seconds, maximum 5 seconds.
2 Hashing ()
We are asking you to implement a Lexicon structure to store arbitrarily long strings of ASCII 
chars (i.e. words). Lexicon L uses a Hash Table T structure along with an Array A of NUL 
separated words. In our case words are going to be English character words only (upper-case or 
lower case). Table T will be organized as a hash-table using collision-resolution by openaddressing as specified in class. You are going to use quadratic probing for h(k,i) and keep the 
choice of the quadratic function simple: i 2 so that h(k,i) = (h 0 (k)+i 2 ) mod N. The keys that 
you will hash are going to be English words. Thus function h 0 (k) is also going to be kept
simple: the sum of the ASCII/Unicode values of the characters minus 2 mod N, where N is the 
number of slots of T. Thus ’alex’ (the string is between the quotation marks) is mapped to 97 + 
108 + 101 + 120 − 2 mod N whatever N is. In the example below, for N = 11, h(alex,0) = 6. 
Table T however won’t store key k in it. This is because the keys are of arbitrary length. Instead, 
T will store pointers/references in the form of an index to another array A. The second table, 
array A will be a character array and will store the words maintained in T separated by NUL 
values \0. This is not 2 characters a backslash followed by a zero. It is 1B (ASCII), 2B 
(UNICODE) whose all bits are set to 0, the NUL value. If you don’t know what B is, it is a byte;
An insertion operation affects T and A. A word w is hashed, an available slot in T is computed 
and let that slot be t. In T[t] we store an index to table A. This index is the first location that 
stores the first character of w. The ending location is the \0 following w in A. New words that do 
not exist (never inserted, or inserted but subsequently deleted) are appended in A. Thus originally 
you need to be wise enough in choosing the appropriate size of A. If at some point you run-out of 
space, you increase T and thus this increases A as well. Doubling T i.e. N, is the option that you 
will use. This causes problems that you also need to attend to. A deletion will modify T as needed 
but will not erase w from A. Let it be there. So A might get dirty (i.e. it contains garbage) after 
several deletions. If several operations later you end up inserting w after deleting it previously, 
you do it the insertion way and you reinsert w, even if a dirty copy of it might still be around. 
You DO NOT DO a linear search to find out if it exists arleady in A; it is inefficient. There is not 
much to say for a search.
You need to support few more operations: Print , Create, Empty/Full/Batch with the last of those 
checking for an empty or full table/array and a mechanism to perform multiple operations in 
batch form. Print prints nicely T and its contents i.e. index values to A. In addition it prints nicely 
(linear-wise in one line) the contents of A. (For a \0 you will do the SEMI obvious: print a 
backslash but not its zero). The intent of Print is to assist the grader. Print however does not print 
the words of A for deleted words. It prints stars for every character of a deleted word instead. (An 
alternative is that during deletion each such character has already been turned into a star: if you 
do so report it to the .txt file to avoid penalties.) Function Create creates T with N slots, and A 
with 15N chars and initializes A to spaces. We call a class that supports and realizes A and T a 
lexicon: L is one instance of a lexicon. Your code should thus implement as functions minimally 
the functions mentioned above: Create, Print, Empty, Full, Batch, Insert, Delete, Search. Testing 
utilizes a Batch function with argument a filename that is going to be provided as a command 
line argument. That file consists of multiple lines containing one command per line. An example 
file is provided in Section B of the course web-page related to the example below. Each 
command is a numeric equivalent of the function named earlier plus one more (for comment). 
Command 10 is Insert, Command 11 is Deletion, and Command 12 is Search. Command 13 is 
Print, Command 14 is Create. Command 15 is Comment: the rest of the line marked by a 15 is 
ignored. Command 14 for create has an argument which is the value of N. Each one of 10, 11, 
and 12 has an argument which is a string (word). If you try to build an interactive system your 
submission will get 0 pts. Input can only be read from a file as specified.

![image](https://user-images.githubusercontent.com/96656870/202301448-874274fd-cd4a-4e00-8c30-0704e98f1700.png)


The six-line batch file above will silently execute commands 14, 10, 15. Command 13 will print 
the following on standard output (screen): T and A. The T entries of 0, 5, 9 are the indexes (first 
position) for alex, tom, jerry of A respectively. Note that the ASCII values of ’alex’ hash into a a 
6, but for ’tom’ and ’jerry’ both hash into a 4, i.e. a collision occurs. A minimal output for Print is 
available below. The backslash after the x or m or y in A indicate a NUL byte (8 bit that are 
zero). The formal ASCII representation is \ 0 but we need to use one character for a NUL byte 
and thus \ is shown

![image](https://user-images.githubusercontent.com/96656870/202301630-95dfbf6b-12c7-42ec-8407-45908d8f983a.png)

![image](https://user-images.githubusercontent.com/96656870/202301672-bb7597d0-35f8-402b-bd5b-796eb943c739.png)

![image](https://user-images.githubusercontent.com/96656870/202301751-358f9805-7f77-4553-b353-e04b7747fc13.png)
