#!/bin/sh

if [ ! -r flipabit ]
then
  make
fi

echo "Running original program"
./hello >& gold.out

for pos in `seq 0 6614`
do
  echo -n "Introducing random mutation to a bit in byte $pos... "
  ./flipabit hello hello.$pos $pos >& pos.log
  chmod +x hello.$pos

  ./hello.$pos >& $pos.out
  diff gold.out $pos.out >& $pos.out.diff

  if [ $? == 0 ]
  then
    echo " PASS"
  else
    echo " FAIL"
  fi
done
