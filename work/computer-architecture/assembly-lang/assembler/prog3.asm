L1:
add $t0,$zero,$s0
ll $t1,0($s1)
sc $t0,0($s1)
beq $t0,$zero,L1
lhu $s2,0($s1)
lui $s2,10
