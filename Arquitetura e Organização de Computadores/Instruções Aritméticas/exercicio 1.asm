.data

.text
    main:
    li		$t0,15 
    li		$t1,30 		

    add		$t3, $t0, $t1	

    li		$v0,1

    move 	$a0, $t3

    syscall
