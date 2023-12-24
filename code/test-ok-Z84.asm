
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,-4(%14)
@para1:
		SUBS	%15,$4,%15
		MOV	$0,-8(%14)
@para_body1:
		CMPS 	-8(%14),$4
		JGES	@para_exit1
@petlja1:
		ADDS	-4(%14),$1,-4(%14)
		ADDS	-8(%14),$2,-8(%14)
		JMP	@para_body1
@para_exit1:
@para3:
		SUBS	%15,$4,%15
		MOV	$0,-8(%14)
@para_body3:
		CMPS 	-8(%14),$4
		JGES	@para_exit3
@petlja3:
		ADDS	-4(%14),$1,-4(%14)
		ADDS	-8(%14),$2,-8(%14)
		JMP	@para_body3
@para_exit3:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET