
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$7,-4(%14)
		MOV 	$7,-8(%14)
		ADDS	-4(%14),$1,-4(%14)
		ADDS	-8(%14),$1,-8(%14)
		ADDS	-4(%14),-8(%14),%0
		ADDS	-4(%14),$1,-4(%14)
		ADDS	-8(%14),$1,-8(%14)
		MOV 	%0,-12(%14)
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET