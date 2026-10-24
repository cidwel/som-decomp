; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121

.segment "CODE"
.org $14C5
actor_script_current_target_clear:
    .a8
    lda #$FF
    sta a:$01AC,Y
    jmp advance_actor_script_1_bytes
