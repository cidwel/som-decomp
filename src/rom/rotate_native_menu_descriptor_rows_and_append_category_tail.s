; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-descriptor-order.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D319
rotate_native_menu_descriptor_rows_and_append_category_tail:
    sep #$20
    lda a:$1847
    .a8
    cmp #$03
    bne rotate_native_menu_descriptor_rows_and_append_category_tail_d0d32d
    lda a:$1846
    rep #$30
    .a16
    and #$00FF
    sta a:$182E
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d32d:
    rep #$30
    lda a:$182E
    beq rotate_native_menu_descriptor_rows_and_append_category_tail_d0d364
    lda a:$182E
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d337:
    pha
    .i16
    ldx #$0000
    lda a:$1880,X
    pha
    lda a:$18A0,X
    pha
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d343:
    lda a:$1882,X
    .a16
    cmp #$FFFF
    beq rotate_native_menu_descriptor_rows_and_append_category_tail_d0d358
    sta a:$1880,X
    lda a:$18A2,X
    sta a:$18A0,X
    inx
    inx
    bra rotate_native_menu_descriptor_rows_and_append_category_tail_d0d343
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d358:
    pla
    sta a:$18A0,X
    pla
    sta a:$1880,X
    pla
    dec
    bne rotate_native_menu_descriptor_rows_and_append_category_tail_d0d337
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d364:
    lda a:$1809
    .a16
    and #$00FF
    .a16
    cmp #$0004
    bcc rotate_native_menu_descriptor_rows_and_append_category_tail_d0d396
    lda a:$1847
    .a16
    and #$00FF
    bne rotate_native_menu_descriptor_rows_and_append_category_tail_d0d396
    .i16
    ldx #$0000
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d37a:
    lda a:$1880,X
    .a16
    cmp #$FFFF
    beq rotate_native_menu_descriptor_rows_and_append_category_tail_d0d386
    inx
    inx
    bra rotate_native_menu_descriptor_rows_and_append_category_tail_d0d37a
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d386:
    sta a:$1882,X
    lda f:$D8FF16
    sta a:$1880,X
    .a16
    lda #$FFFF
    sta a:$1882,X
rotate_native_menu_descriptor_rows_and_append_category_tail_d0d396:
    rts
