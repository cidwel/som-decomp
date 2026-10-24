; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $04D0
dispatch_dialogue_window_tile_orientation:
    .a8
    lda #$00
    xba
    lda a:$A16D
    asl
    rep #$20
    phx
    tax
    pla
    sep #$20
    jsr ($10FA,X)
    rts
