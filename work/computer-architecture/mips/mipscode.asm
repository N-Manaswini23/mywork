.data
 printN :.asciiz "Enter N(number of terms)\n"
 printa : .asciiz "Enter a(scale factor)\n"
 printr : .asciiz "Enter r(common ratio)\n"
 print_inc_b :.asciiz "increasing sequence before sort\n"
 print_dec_b :.asciiz "decreasing sequence before sort\n"
 print_rand_b :.asciiz "random sequence before sort\n"
 print_aft_sort: .asciiz "After insertion sort\n"
 comparisions: .asciiz "number of comparisions="
 newline : "\n"
 space : .asciiz "  "
 remainder : .asciiz "remainder "
 array1: .word   0 : 100
 array2: .word   0 : 100  
.text 
main:
li $v0, 4 #4= system code for printing a string
la $a0,printN 
syscall
li $v0,5 #5= system code for user input
syscall
move $t0, $v0 #t0=v0
li $v0, 4 #4= system code for printing a string
la $a0,printa 
syscall
li $v0,5 #5= system code for user input
syscall
move $t1, $v0 #t1=v0
li $v0, 4 #4= system code for printing a string
la $a0,printr 
syscall 
li $v0,5 #5= system code for user input
syscall 
move $t2, $v0 #t2=v0
add $a1, $zero, $t0# a1 =t0
add $a2, $zero, $t1 # a2=t1
add $a3, $zero, $t2 # a3=t2
addi $s1,$zero,2
jal generate_increasingorder
main2:jal insertionsort
      li $v0, 4 #4= system code for printing a string
      la $a0,print_aft_sort 
      syscall
      jal printarr
      jal generate_decreasingorder
main3:jal insertionsort
      li $v0, 4
      la $a0,print_aft_sort 
      syscall
      jal printarr
      jal generate_randomorder
main4:jal insertionsort
      li $v0, 4 
      la $a0,print_aft_sort 
      syscall
      jal printarr
      li $v0, 10 # system call for terminating the execution 
      syscall 


insertionsort:
add $t1,$zero,$zero#t1=comp
add $t2,$zero,$zero#t2=i
addi $s1,$a1,-1#s1=N-1
for1:add $t3,$zero,$t2#t3=j
     addi $t2,$t2,1#t2=i+1
     sll $t6,$t2,2#t6=4*(i+1)
     lw $t5,array1($t6)#t5=arr(i+1)=temp
     addi $t1,$t1,1
     addi $t6,$t3,1 #t6=j+1
      sll $t6,$t6,2 #t6=4*(j+1)
      j while2
while2:
       lw $t8,array1($t6)#t8=rr(j+1)
       sll $t7,$t3,2#t7=4*j
       lw $t9,array1($t7)#t9=arr(j)
       slt $t4,$t5,$t9#t4=1 if temp<arr(j)
       beq $t4,$zero,assign1#if temp>=arr(j)
       sw $t9,array1($t6)#arr(j+1)=arr(j)
       addi $t3,$t3,-1#j=j-1
       addi $t6,$t3,1 #t6=j+1
       sll $t6,$t6,2 #t6=4*(j+1)
       slt $t4,$t3,$zero#t4=1 if j<0
       bne $t4,$zero,assign1#if j<0
       addi $t1,$t1,1
       j while2
assign1:sw $t5,array1($t6)#arr(j+1)=temp
        slt $s2,$t2,$s1#s2=1 if i<N-1
        beq $s2,$zero,exiti#if i>=N-1 exit
        j for1
  
exiti:li $v0, 4
      la $a0,comparisions
      syscall
      li $v0, 1
      add $a0,$t1,$zero
      syscall
      li $v0, 4
       la $a0,newline
       syscall
      jr $ra










generate_increasingorder:
add $s1,$zero,$zero
add $t2,$zero,$zero
j loop1
loop1:jal pow
      sw  $v1,array1($t2)
      addi $s1,$s1,1
      addi $t2,$t2,4
      slt $t4,$s1,$a1 
      bne $t4,$zero,loop1 
exit1:
      li $v0, 4 
      la $a0,print_inc_b 
      syscall
      jal printarr
      j main2
      
      
      
      
generate_decreasingorder:
addi $s1,$a1,-1
add $t2,$zero,$zero
j loop4
loop4:jal pow
      sw  $v1,array1($t2)
      addi $s1,$s1,-1
      addi $t2,$t2,4
      slt $t4,$s1,$zero 
      beq $t4,$zero,loop4
exit4:
      li $v0, 4 
      la $a0,print_dec_b 
      syscall
      jal printarr
      j main3



generate_randomorder:
jal initializearr
add $s1,$zero,$zero
add $t2,$zero,$zero
add $t7,$zero,$a1
while1: li $v0, 42  # 42 is system call code to generate random int
      li $a1, 100 # $a1 is where you set the upper bound
      syscall  # your generated number will be at $a0
      add $t3,$a0,$zero 
      div $t3,$t7
      mfhi $t6
      sll $t5,$t6,2
       lw $t1,array1($t5)
       bne $t1,$zero,while1
loop6:
      jal pow
      sw  $v1,array1($t5)
      addi $s1,$s1,1
      addi $t2,$t2,4
      slt $t4,$s1,$t7 
      bne $t4,$zero,while1
exit5:add $a1,$zero,$t7
      li $v0, 4 
      la $a0,print_rand_b
      syscall
      jal printarr
      j main4
      
      



pow:
add $s2,$zero,$zero
addi $t6,$zero,1
beq $s1,$zero,exit2
loop2: beq $s2,$s1,exit2
       mul $t6,$a3,$t6
       addi $s2,$s2,1
       j loop2
exit2: mul $t6,$t6,$a2
       add $v1,$t6,$zero
       jr $ra

printarr:
add $s2,$zero,$zero
loop3:sll $t3,$s2,2
      lw $a0, array1($t3)
      li $v0, 1 
      syscall
      li $v0, 4
      la $a0,space
      syscall
      addi $s2,$s2,1
      slt $t2,$s2,$a1
      bne $t2,$zero,loop3
exit3: li $v0, 4
       la $a0,newline
       syscall
       jr $ra
       
       
initializearr:
add $s2,$zero,$zero
add $t1,$zero,$zero
loop8:sll $t3,$s2,2
      sw $t1, array1($t3)
      addi $s2,$s2,1
      slt $t2,$s2,$a1
      bne $t2,$zero,loop8
exit8:jr $ra
       
       


