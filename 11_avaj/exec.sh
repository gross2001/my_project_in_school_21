#! /bin/bash

#rm $(find . -name "*.class")

find * -name "*.java" > sources.txt
javac @sources.txt

java ro.academyplus.avaj.sumulator.Simulator scenario.txt

