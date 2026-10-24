; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

adjust_native_menu_icon_position_for_name_page = $6CEB

.segment "CODE"
.org $5F20
select_native_menu_icon_position_and_tile_cursor:
    rep #$20
    .a16
    and #$00FF
    pha
    asl
    tax
    lda f:$C75FE7,X
    sta a:$A159
    pla
    .a16
    and #$0003
    asl
    pha
    asl
    asl
    asl
    clc
    .a16
    adc #$5FA7
    tax
    pla
    inc
    asl
    asl
    asl
    asl
    tay
    sep #$20
    jsr adjust_native_menu_icon_position_for_name_page
    rts
