; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $09CD
set_scrolling_dialogue_line_indentation:
    iny
    rep #$20
    lda a:$9000,Y
    iny
    .a16
    and #$00FF
    asl
    clc
    adc a:$A18F
    sta a:$A19B
    sep #$20
    rts
