L1:
addi $sp,$sp,-12
sw $ra,8($sp)
sh $a0,0($sp)
sh $a1,4($sp)
sltiu $s1,$a0,20
bne $s1,$zero,L2
addi $v0,$zero,0
addi $sp,$sp,8
jr $ra
L2:
and $s2,$a0,$a1
or $s3,$a0,$a1
nor $s4,$s2,$s3
andi $s4,$s4,10
ori $s4,$s4,10
sll $s4,$s4,10
srl $s4,$s4,10
addi $sp,$sp,12
jr $ra
