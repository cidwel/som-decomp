; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-descriptor-sources.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D1AE
build_fixed_seven_native_menu_descriptor_rows:
    lda a:$1828
    tax
    .a16
    lda #$0007
build_fixed_seven_native_menu_descriptor_rows_d0d1b5:
    pha
    lda f:$D8FD60,X
    sta a:$0000,Y
    iny
    iny
    inx
    inx
    pla
    dec
    bne build_fixed_seven_native_menu_descriptor_rows_d0d1b5
    lda a:$1876
    .a16
    and #$00FF
    sta a:$182E
    rts
