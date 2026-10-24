; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $0111
advance_actor_script_and_yield:
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:ACTOR_PROGRAM_PC,Y
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$0000
    rts
