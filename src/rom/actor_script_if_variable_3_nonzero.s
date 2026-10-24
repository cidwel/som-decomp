; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_1_bytes = $0285
read_actor_script_variable_3 = $0187
skip_actor_script_after_1_bytes = $0213



.segment "CODE"
.org $0675
actor_script_if_variable_3_nonzero:
    jsr read_actor_script_variable_3
    .a8
    cmp #$00
    bne actor_script_if_variable_3_nonzero_c10681
    jsr skip_actor_script_after_1_bytes
    bra actor_script_if_variable_3_nonzero_c10684
actor_script_if_variable_3_nonzero_c10681:
    jsr jump_actor_script_after_1_bytes
actor_script_if_variable_3_nonzero_c10684:
    rts
