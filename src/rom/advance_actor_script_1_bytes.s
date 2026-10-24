; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144

.segment "CODE"
.org $0121
advance_actor_script_1_bytes:
    rep #$20
    tyx
    inc a:ACTOR_PROGRAM_PC,X
    .a16
    lda #$FFFF
    rts
