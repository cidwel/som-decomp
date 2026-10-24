; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-upload.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C86C
resolve_twelve_native_menu_icon_descriptor_words:
    sep #$20
    .i16
    ldy #$18C0
    .i16
    ldx #$1880
    .a8
    lda #$0C
resolve_twelve_native_menu_icon_descriptor_words_d0c876:
    pha
    phx
    lda a:$0000,Y
    iny
    .a8
    cmp #$FF
    bne resolve_twelve_native_menu_icon_descriptor_words_d0c887
    rep #$20
    .a16
    lda #$FFFF
    bra resolve_twelve_native_menu_icon_descriptor_words_d0c897
resolve_twelve_native_menu_icon_descriptor_words_d0c887:
    rep #$20
    .a16
    and #$00FF
    asl
    clc
    adc f:$D8FD62
    tax
    lda f:$D8FD60,X
resolve_twelve_native_menu_icon_descriptor_words_d0c897:
    plx
    sta $00,X
    inx
    inx
    sep #$20
    pla
    dec
    bne resolve_twelve_native_menu_icon_descriptor_words_d0c876
    rts
