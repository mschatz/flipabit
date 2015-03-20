#!/bin/sh

if [ ! -r flipabit ]
then
  make
fi

echo "Running original program"
./hello

echo "Introducing random mutation to a bit in byte 1270 (picked at random)"
./flipabit hello hello.1270 1270
chmod +x hello.1270

echo "Testing mutant"
./hello.1270

echo "Confirming the presense of a mutation"
od -x hello > hello.x
od -x hello.1270 > hello.1270.x

diff hello.x hello.1270.x


