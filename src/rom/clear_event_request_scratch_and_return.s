; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E881
clear_event_request_scratch_and_return:
    rep #$10
    sep #$20
    stz $CC
    stz $CD
    stz $CE
    plx
    rts
