# p4-4760
<br>Name: Elisa Reyes
<br>Date: 10/29
<br>Environment: vi, visual studio code
<br>How to compile the project: Type 'make'
<br>Type 'make clean' to do a clean
<br>Example of how to run the project: ./oss -n 3 -s 2 -t 4 -i 0.6 -f log.txt
<br>Generative AI used: chatgpt(codex)
<br>Prompts:
implement the scheduling algorithm that will select the process by using a multilevel feedback queue with 3 separate queues as the scheduler. When new processes are launched, they should be put into the highest priority queue. Every time oss has to make a scheduling decision it will select the process at the front of the highest priority queue that has something in it. Processes selected from q0 should be given a time quantum of 25ms, q1 given 50 ms, and q2 of 100ms. If a process uses up all of its time quantum, it should be put in the next lower queue. Put the process at the back of the queue if it's already in the lowest queue.
Once a process becomes unblocked, it should be put in the highest priority queue. When processes become unblocked or give back control to oss, they should be put at the back of the queue. Before each scheduling decision, output the set of
queues.
<br>Summary: The generated code seemed to have a good implemntation of the scheduling algorithm