; load the registers with some value
LDA $7000
LDY $7001
LDB #$01
LDY #$F6

; begin inner loop
INA
INB
INX
INY
SUM_BA
STDOUT $7002
STDOUT $7003
STDOUT $7004

; go back to INA above until Y = 0 (overflow)
BNE_Y $000A

; exit
BRK
