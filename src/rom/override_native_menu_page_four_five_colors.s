; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $212F
override_native_menu_page_four_five_colors:
    .a8
    cmp #$04
    beq override_native_menu_page_four_five_colors_c02137
    .a8
    cmp #$05
    bne override_native_menu_page_four_five_colors_c02168
override_native_menu_page_four_five_colors_c02137:
    .i16
    ldx #$000C
    .i16
    ldy #$0002
    .a8
    lda #$06
    phy
override_native_menu_page_four_five_colors_c02140:
    xba
    lda f:$D2DBC0,X
    sta a:$9018,Y
    sta a:$9028,Y
    inx
    iny
    xba
    dec
    bne override_native_menu_page_four_five_colors_c02140
    ply
    .i16
    ldx #$0024
    .a8
    lda #$06
override_native_menu_page_four_five_colors_c02157:
    xba
    lda f:$D2DBC0,X
    sta a:$9010,Y
    sta a:$9020,Y
    inx
    iny
    xba
    dec
    bne override_native_menu_page_four_five_colors_c02157
override_native_menu_page_four_five_colors_c02168:
    rts
