; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_1_bytes = $0285
read_actor_script_variable_0 = $015B
skip_actor_script_after_1_bytes = $0213



.segment "CODE"
.org $0685
actor_script_if_variable_0_zero:
    jsr read_actor_script_variable_0
    .a8
    cmp #$00
    beq actor_script_if_variable_0_zero_c10691
    jsr skip_actor_script_after_1_bytes
    bra actor_script_if_variable_0_zero_c10694
actor_script_if_variable_0_zero_c10691:
    jsr jump_actor_script_after_1_bytes
actor_script_if_variable_0_zero_c10694:
    rts
