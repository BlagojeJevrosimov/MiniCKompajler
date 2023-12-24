
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
		CMPS 	-8(%14),$8
		JGES	@para_exit1
@petlja1:
@para2:
		SUBS	%15,$4,%15
		MOV	$0,-12(%14)
@para_body2:
		CMPS 	-12(%14),$8
		JGES	@para_exit2
@petlja2:
		ADDS	-4(%14),$1,-4(%14)
		ADDS	-12(%14),$1,-12(%14)
		JMP	@para_body2
@para_exit2:
		ADDS	-8(%14),$1,-8(%14)
		JMP	@para_body1
@para_exit1:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET