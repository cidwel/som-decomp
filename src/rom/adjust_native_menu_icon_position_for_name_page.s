; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6CEB
adjust_native_menu_icon_position_for_name_page:
    lda a:$A202
    .a8
    cmp #$04
    bne adjust_native_menu_icon_position_for_name_page_c76d16
    lda a:$A136
    pha
    .a8
    and #$03
    asl
    asl
    clc
    .a8
    adc #$06
    sta a:$A15A
    pla
    .a8
    and #$FC
    clc
    .a8
    adc #$06
    sta a:$A159
    lda a:$A22B
    .a8
    cmp #$02
    bne adjust_native_menu_icon_position_for_name_page_c76d16
    dec a:$A15A
    inc a:$A159
adjust_native_menu_icon_position_for_name_page_c76d16:
    rts
