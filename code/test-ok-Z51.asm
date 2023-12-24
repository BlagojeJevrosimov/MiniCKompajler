
a:
		PUSH	%14
		MOV 	%15,%14
@a_body:
		JMP 	@a_exit
@a_exit:
		MOV 	%14,%15
		POP 	%14
		RET
b:
		PUSH	%14
		MOV 	%15,%14
@b_body:
@b_exit:
		MOV 	%14,%15
		POP 	%14
		RET
prov1:
		PUSH	%14
		MOV 	%15,%14
@prov1_body:
		JMP 	@prov1_exit
@prov1_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		MOV 	$0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET