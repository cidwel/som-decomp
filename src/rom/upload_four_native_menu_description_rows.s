; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_wram_source_for_native_menu_tile_dma = $25CC

.segment "CODE"
.org $279E
upload_four_native_menu_description_rows:
    .a8
    lda #$04
    sta a:$A175
    .i16
    ldy #$58C1
    sty a:$A173
    .i16
    ldy #$9182
    sty a:$A194
upload_four_native_menu_description_rows_c027af:
    rep #$20
    lda a:$A173
    pha
    sta f:$002116
    .a16
    lda #$0078
    sta a:$A191
    sep #$20
    jsr select_wram_source_for_native_menu_tile_dma
    rep #$20
    pla
    clc
    .a16
    adc #$0020
    sta a:$A173
    lda a:$A194
    clc
    .a16
    adc #$0040
    sta a:$A194
    sep #$20
    dec a:$A175
    bne upload_four_native_menu_description_rows_c027af
    rts
