; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-strip.md.
.setcpu "65816"
.smart
.a8
.i16

advance_menu_icon_palette_and_select_descriptor_tile = $C979
initialize_twelve_native_icon_rows_and_publish_upper_palette = $D0CB11

.segment "CODE"
.org $C8A3
upload_native_twelve_icon_strip_and_upper_palette:
    sep #$20
    .a8
    lda #$FB
    sta a:$1810
    .i16
    ldx #$1880
    .a8
    lda #$0C
upload_native_twelve_icon_strip_and_upper_palette_d0c8af:
    pha
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    sep #$20
    pla
    .a8
    cmp #$05
    bne upload_native_twelve_icon_strip_and_upper_palette_d0c8ca
    pha
    rep #$20
    lda a:$180C
    clc
    .a16
    adc #$0100
    sta a:$180C
    sep #$20
    pla
upload_native_twelve_icon_strip_and_upper_palette_d0c8ca:
    dec
    bne upload_native_twelve_icon_strip_and_upper_palette_d0c8af
    jsl f:initialize_twelve_native_icon_rows_and_publish_upper_palette
    rep #$20
    sep #$10
    .i8
    ldx #$C0
    stx a:$2121
    .i8
    ldx #$00
    stx a:$4350
    .i8
    ldx #$22
    stx a:$4351
    .a16
    lda #$0780
    sta a:$4352
    .i8
    ldx #$00
    stx a:$4354
    .a16
    lda #$0080
    sta a:$4355
    .i8
    ldx #$20
    stx a:$420B
    rts
