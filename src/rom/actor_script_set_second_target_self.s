; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121

ACTOR_SECOND_TARGET = $01AD

.segment "CODE"
.org $1635
actor_script_set_second_target_self:
    rep #$20
    tya
    sec
    .a16
    sbc #$E000
    sep #$20
    xba
    lsr
    sta a:ACTOR_SECOND_TARGET,Y
    jmp advance_actor_script_1_bytes
