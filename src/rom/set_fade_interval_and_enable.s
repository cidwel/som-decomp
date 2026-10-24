; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8B36
set_fade_interval_and_enable:
    sty $E4
    .a8
    lda #$01
    tsb $E2
    rts
