# a short discription for each file
## lab4_question2:
The goal is to maximize CPU utilization under a special circumstance.
It works like this: make **MAXCHILD** children and **MAXCHILD** is a number between 2 and 10.
Each child makes a random number between 1 and 1000 and waits for this random number second, then  prints the message(PID is ID of the created process):
> Message from child PID: waited for RANDOM seconds
The parent process checks all children if one of them is ended, it creates a new child(has its own function).
Parent process continues until it receives a signal like **CTRL+C** .

