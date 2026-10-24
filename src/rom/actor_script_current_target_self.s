; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121

.segment "CODE"
.org $14AB
actor_script_current_target_self:
    rep #$20
    tya
    sec
    .a16
    sbc #$E000
    sep #$20
    xba
    lsr
    sta a:$01AC,Y
    jmp advance_actor_script_1_bytes
