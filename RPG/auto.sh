#!/bin/sh
file=program
if [ -e $(file)]; then
	make
fi
./program hero.txt enemies.txt 1.0
