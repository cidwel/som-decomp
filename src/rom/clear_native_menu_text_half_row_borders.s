; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $23AD
clear_native_menu_text_half_row_borders:
    .a8
    lda #$04
clear_native_menu_text_half_row_borders_c023af:
    stz a:$9400,X
    stz a:$942C,X
    inx
    dec
    bne clear_native_menu_text_half_row_borders_c023af
    rts
