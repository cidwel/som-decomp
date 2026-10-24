; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $013B
advance_actor_script_3_bytes:
    rep #$20
    lda a:ACTOR_PROGRAM_PC,Y
    clc
    .a16
    adc #$0003
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$FFFF
    rts
