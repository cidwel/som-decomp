; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_2_bytes = $012B

.segment "CODE"
.org $1FDE
actor_script_second_target_from_literal_byte:
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$01AD,Y
    jmp advance_actor_script_2_bytes
