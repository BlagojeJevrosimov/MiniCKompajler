
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		CMPS 	-4(%14),$5
		JNE 	@tranga_false0
		JMP	jiro_exit0
@tranga_false0:
		CMPS 	-4(%14),$9
		JNE 	@tranga_false1
		JMP	jiro_exit0
@tranga_false1: