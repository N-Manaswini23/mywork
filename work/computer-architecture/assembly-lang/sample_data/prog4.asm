L1:
addi $sp,$sp,-8
sw $ra,4($sp)
sw $a0,0($sp)
sltu $t1,$a0,$a1
bne $t1,$zero,L2
addi $v0,$zero,0
addi $sp,$sp,8
jr $ra
L2:
sub $a0,$a0,$a1
jal L1
lw $a0,0($sp)
lw $ra,4($sp)
addi $sp,$sp,8
add $v0,$s0,$v0
jr $ra
