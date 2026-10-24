; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6D57
publish_native_menu_twenty_nine_column_tile_strip:
    .i16
    ldx #$2090
    bra publish_native_menu_twenty_nine_column_tile_strip_c76d5f
    .i16
    ldx #$2108
publish_native_menu_twenty_nine_column_tile_strip_c76d5f:
    rep #$20
    .a16
    lda #$001D
    sta a:$A171
    phx
    .i16
    ldx #$0042
    pla
publish_native_menu_twenty_nine_column_tile_strip_c76d6c:
    sta a:$9000,X
    inc
    inc
    sta a:$9040,X
    inx
    inx
    inc
    inc
    dec a:$A171
    bne publish_native_menu_twenty_nine_column_tile_strip_c76d6c
    stz a:$9000,X
    stz a:$9040,X
    sep #$20
    .a8
    lda #$02
    tsb a:$A20A
    rtl
