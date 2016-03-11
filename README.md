# 555IC-calculator
This C program will calculate the square wave for the astable configuration of the chip, as well as the timeout for the monostable configuration.

+5 ---+---------------+---+
      |               |   |
      R            +----------+
      |(see below) |  8   4   |
  +---+------+-----|7        3|------/\/\/\---+------- Vout
  :          |     |  LMC555  |               |
  C to test  +-----|6         |             -----
  :                |          |             -----
ground       +-----|2        5|----+          |
             |     |    1     |    |        ground
             |     +----------+  0.1 uF
             |          |          |
   Clock ----+        ground     ground
     ^
     
# How to
git clone https://github.com/xdth/555IC-calculator.git

cd 555IC-calculator

cc -std=c11 -Wall -Wextra -g -pedantic -o 555calc 555calc.c
