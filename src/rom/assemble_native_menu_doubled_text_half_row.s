; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_text_half_row_borders = $23AD

.segment "CODE"
.org $2387
assemble_native_menu_doubled_text_half_row:
    jsr clear_native_menu_text_half_row_borders
    .a8
    lda #$06
assemble_native_menu_doubled_text_half_row_c0238c:
    xba
    lda a:$9000,Y
    sta a:$9400,X
    sta a:$9401,X
    lda a:$9006,Y
    iny
    sta a:$941C,X
    sta a:$941D,X
    inx
    inx
    xba
    dec
    bne assemble_native_menu_doubled_text_half_row_c0238c
    iny
    iny
    iny
    iny
    iny
    iny
    rts
