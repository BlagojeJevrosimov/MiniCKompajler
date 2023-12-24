
f:
		PUSH	%14
		MOV 	%15,%14
@f_body:
		MOV 	$0,%13
		JMP 	@f_exit
@f_exit:
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
prov2:
		PUSH	%14
		MOV 	%15,%14
@prov2_body:
@prov2_exit:
		MOV 	%14,%15
		POP 	%14
		RET
v:
		PUSH	%14
		MOV 	%15,%14
@v_body:
		JMP 	@v_exit
@v_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$20,%15
@main_body:
		MOV 	$12,-4(%14)
		MOV 	$12,-8(%14)
		MOV 	$12,-12(%14)
		MOV 	$15,-16(%14)
		MOV 	$15,-20(%14)
		ADDS	-4(%14),$1,-4(%14)
		SUBS	-4(%14),-4(%14),%0
		ADDS	-4(%14),$1,-4(%14)
		MOV 	%0,-8(%14)
@para1:
		SUBS	%15,$4,%15
		MOV	$0,-24(%14)
@para_body1:
		CMPS 	-24(%14),$17
		JGES	@para_exit1
@petlja1:
@para2:
		SUBS	%15,$4,%15
		MOV	$0,-28(%14)
@para_body2:
		CMPS 	-28(%14),$20
		JGES	@para_exit2
@petlja2:
		ADDS	-24(%14),$1,-24(%14)
		ADDS	-28(%14),$2,-28(%14)
		JMP	@para_body2
@para_exit2:
		ADDS	-24(%14),$2,-24(%14)
		JMP	@para_body1
@para_exit1:
		CMPU 	-16(%14),$5
		JNE 	@tranga_false0
		ADDS	-8(%14),-12(%14),%0
		MOV 	%0,-4(%14)
		JMP	jiro_exit0
@tranga_false0:
		CMPU 	-16(%14),$7
		JNE 	@tranga_false1
		SUBS	-8(%14),-12(%14),%0
		MOV 	%0,-4(%14)
@tranga_false1:
		CMPU 	-16(%14),$9
		JNE 	@tranga_false2
		ADDS	-4(%14),$1,-4(%14)
		JMP	jiro_exit0
@tranga_false2:
		MOV 	$0,-4(%14)
jiro_exit0:
		CMPS 	-8(%14),$5
		JNE 	@tranga_false3
		ADDS	-8(%14),-12(%14),%0
		MOV 	%0,-4(%14)
		JMP	jiro_exit1
@tranga_false3:
		CMPS 	-8(%14),$7
		JNE 	@tranga_false4
		SUBS	-8(%14),-12(%14),%0
		MOV 	%0,-4(%14)
@tranga_false4:
		CMPS 	-8(%14),$9
		JNE 	@tranga_false5
		ADDS	-4(%14),$1,-4(%14)
		JMP	jiro_exit1
@tranga_false5:
jiro_exit1:
		MOV 	$0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET