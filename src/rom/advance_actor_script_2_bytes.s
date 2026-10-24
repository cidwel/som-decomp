; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $012B
advance_actor_script_2_bytes:
    rep #$20
    lda a:ACTOR_PROGRAM_PC,Y
    clc
    .a16
    adc #$0002
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$FFFF
    rts
