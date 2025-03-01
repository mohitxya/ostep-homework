## Solutions:

1. Self-Explanatory
2. Self-Explanatory
3. 
* a forks b
* b exits
* a forks c
* c forks d
* a forks e

4. What happens to orphaned processes?
* a ---b 
* a---b---c 
* a--b--c--e
*       |__d
* c exits: then The child processes get attached to the root node, i.e a.
* the above happens when there is no -R flag. 
* with R-flag the children get attached to the immediate parent of c, i.e. b.

> In a Unix-like operating system any orphaned process will be immediately adopted by an implementation-defined system process: the kernel sets the parent to this process. This operation is called re-parenting and occurs automatically. Even though technically the process has a system process as its parent, it is still called an orphan process since the process that originally created it no longer exists. In other systems orphaned processes are immediately terminated by the kernel. 




