; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0515
expand_dialogue_window_tile_backward:
    rep #$20
    clc
    .a16
    adc #$000E
    tax
    sep #$20
    .a8
    lda #$08
expand_dialogue_window_tile_backward_c00520:
    xba
    lda f:$D2D080,X
    sta a:$9400,Y
    lda f:$D2D081,X
    sta a:$9401,Y
    ora a:$9400,Y
    sta a:$9410,Y
    .a8
    lda #$00
    sta a:$9411,Y
    dex
    dex
    iny
    iny
    xba
    dec
    bne expand_dialogue_window_tile_backward_c00520
    clc
    rep #$20
    tya
    .a16
    adc #$0010
    tay
    sep #$20
    rts
