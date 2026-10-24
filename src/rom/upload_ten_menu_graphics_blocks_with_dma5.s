; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CDF9
upload_ten_menu_graphics_blocks_with_dma5:
    rep #$30
    .a16
    lda #$00D2
    sta a:$1820
    .a16
    lda #$0000
    tax
upload_ten_menu_graphics_blocks_with_dma5_d0ce05:
    pha
    phx
    clc
    .a16
    adc #$C680
    pha
    lda f:$D0CE53,X
    .a16
    and #$00FF
    clc
    .a16
    adc #$0100
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$6000
    tay
    .a16
    lda #$0040
    plx
    sty a:$2116
    stx a:$4352
    sta a:$4355
    sep #$20
    .a8
    lda #$01
    sta a:$4350
    .a8
    lda #$18
    sta a:$4351
    lda a:$1820
    sta a:$4354
    .a8
    lda #$20
    sta a:$420B
    rep #$30
    plx
    pla
    inx
    clc
    .a16
    adc #$0040
    .a16
    cmp #$0280
    bcc upload_ten_menu_graphics_blocks_with_dma5_d0ce05
    rtl
