### Answers:

1. It creates two processes of 5 instructions with 100% of them utilizing the cpu. So, the cpu utilization time would be: 
* No switching till process 0 finishes its execution: 5 units
* Another 5 units for process 1's execution
* So Total of **10 units**

2. Creates Process 0: 4 instruction, 100% of them utilizing CPU and Process 1: 1 instruction which is IO intensive. 
* Except for RUN:io and RUN:io_done. The IO in Process 1 takes 5 units to complete.
* First, Process 0 finishes the execution of its four instructions. 
* RUN: io: takes one cpu unit, the 5 io units and one final RUN: io_done cpu unit.
* Total of : 4+1+1+5=11 units

3. If we switch the order while PID 0 is blocked PID 1 can continue it's execution.
* First RUN: io takes unit cpu unit (time).
* For the next 5 time units PID 0 remains blocked while PID 1 continues executing.

4. SWITCH_ON_END: flag
* Doesn't allow the process to switch till it has finished execution.

5. SWITCH_ON_IO: flag
* Switches when IO operation starts. (status: BLOCKING) (Similar to 3)

6. IO_RUN_LATER: flag
* When IO operation is finished and RUN: io_done is triggered, The currently executing process keeps running. 
* Ignores io_done. This causes inefficient utilization of cpu resources. 
* We could handle RUN:io_done and the start another IO intensive sequence (Blocking) while runnig another process.

7. IO_RUN_IMMEDIATE: flag
* Handles the issue of question 6 by addressing the RUN: io_done immediately.


