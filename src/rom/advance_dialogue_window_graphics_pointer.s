; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1257
advance_dialogue_window_graphics_pointer:
    rep #$20
    lda a:$A181
    .a16
    and #$00FF
    asl
    tax
    lda f:$C01A3E,X
    clc
    adc a:$A189
    sta a:$A189
    sep #$20
    rts
