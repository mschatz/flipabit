# flipabit
Thought experiment of what happens when a binary program is randomly edited


# Example run:

```
$ ./random_mutate.sh
Running original program
Hello, World!
Introducing random mutation to a bit in byte 1270 (picked at random)
Editing "hello" into "hello.1270" editing byte 1270
-- flipping a bit in byte 1270
copied 6615 bytes and edited 1 bits
Testing mutant
Hello, World!
Confirming the presense of a mutation
80c80
< 0002360 0000 4800 c085 0874 10bf 6007 c900 e0ff
---
> 0002360 0000 4800 c085 0875 10bf 6007 c900 e0ff
```


# Try all possible flips

```
$ ./try_all_flips.sh  >& try.log

## Wait a while, and then hit control-c otherwise will be hung forever

$ grep -c PASS try.log
848
$ grep -c FAIL try.log
459
Created infinite loop on byte 1307
```


