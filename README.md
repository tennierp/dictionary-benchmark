# Dictionary Benchmark

## Student Information
Parker Tennier  
ID: 008768156  
https://github.com/tennierp/dictionary-benchmark.git

## Collaboration & Sources
Dr. Ali A. Kooshesh provided the Unsorted Vector already coded.
I created a Sorted Vector Dict, an Unsorted Linked List, and a Sorted Linked List and I edited the main
file to run the remove function test.

## Implementation Details
I was given the task of creating the Dictionary functions insert, lookup and remove for a Sorted Vector, 
Unsorted Linked List, and Sorted Linked List

Both Linked Lists were created by using a node structure. The node structure had a data key, and a next pointer
pointing to the next node in the List. The Unsorted Linked List pushed the head back and made the new node the head. 
The Sorted Linked list had to scan for the position of the new node and set it in between the current and previous nodes it found. 
The Sorted Vector pushed the new key to the back and moved it up until it was in the right place.

## Testing & Status
Dr. Ali A. Kooshesh created a testing function to find the average time it takes for the insert and lookup operations to work.
I created a function that added N number of variables to the ADT's using insert and lookup, and then called the remove function
on the ADT's to clear them out, showing that the remove function works.

The program will run and give correct times on each ADT using both testing methods.
In result, you will be given the Average time for Insert and Lookup on each individual ADT as well as a test
showing that the remove function works on each of them.