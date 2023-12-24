
f:
		PUSH	%14
		MOV 	%15,%14
@f_body:
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
a:
		PUSH	%14
		MOV 	%15,%14
@a_body:
		ADDS	8(%14),$1,8(%14)
@a_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$7,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET