
f:
		PUSH	%14
		MOV 	%15,%14
@f_body:
		ADDS	8(%14),12(%14),%0
		ADDS	%0,16(%14),%0
		MOV 	%0,%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
			PUSH	$5
			PUSH	$5
			PUSH	$5
			CALL	f
			ADDS	%15,$12,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET