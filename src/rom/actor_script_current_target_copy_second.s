; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121

.segment "CODE"
.org $14BC
actor_script_current_target_copy_second:
    lda a:$01AD,Y
    sta a:$01AC,Y
    jmp advance_actor_script_1_bytes
