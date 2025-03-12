## Solutions:

1. -l 200,200,200.
  * response time: when it first starts executing the job. 
  * turnaround time: Time when it finishes the job. 
  * wait time: Time it spends in waiting state.

  Response time=0+200+400/3=200
  Turnaround time=200+400+600/3= 1200/3 = 400
  Wait time= 0+200+400/3=200

- SJF and FIFO would have the same performance in this case.

2. *100,200,300*
  * response time (SJF): 0+100+300/3=400/3
  * turnaround time: 100+300+600/3=1000/3
  * wait time: 0+100+300/3=400/3

- Same for SJF and FIFO.

3. *RR scheduler*:
- Runs each job for 1 s.
- Can be calculated using Arithmetic progression. 
- For job 1: 0,3,6,....100 such cycles. i.e. 297+1=298. 
- Similarly we can calculate other metrics.

4. 
* When order is same.
* When lengths of all jobs are same.

5. 
- When time quantum equals job length and all jobs have equal length.
- When time quantum = length of the longest job.

6. Response time increases.

7. 
As quantum length increases: The response time increases. (avg) 
Equation (worst-case response time, N jobs): 
