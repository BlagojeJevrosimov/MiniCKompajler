
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$8,-4(%14)
		MOV 	$7,-8(%14)
		CMPU 	-8(%14),$4
		JNE 	@tranga_false0
		ADDS	-4(%14),$1,-4(%14)
		JMP	jiro_exit0
@tranga_false0:
		CMPU 	-8(%14),$8
		JNE 	@tranga_false1
		ADDS	-4(%14),$1,-4(%14)
		JMP	jiro_exit0
@tranga_false1:
		CMPU 	-8(%14),$7
		JNE 	@tranga_false2
		MOV 	$1,-4(%14)
@tranga_false2:
		MOV 	$5,-4(%14)
jiro_exit0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET