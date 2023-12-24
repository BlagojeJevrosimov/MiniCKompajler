
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$5,-4(%14)
		MOV 	$7,-8(%14)
		CMPS 	-8(%14),$5
		JGES	@false0
@true0:
		MOV 	-4(%14),%0
		JMP	@exit0
@false0:
		MOV 	-8(%14),%0
@exit0:
		ADDS	$3,%0,%0
		ADDS	%0,$5,%0
		MOV 	%0,-12(%14)
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET