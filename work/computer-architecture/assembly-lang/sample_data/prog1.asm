slt $t0,$a0,$a1
beq $t0,$zero,L1
sub $s0,$a1,$a0
jr $ra
L1:
sub $s1,$a0,$a1
jr $ra
