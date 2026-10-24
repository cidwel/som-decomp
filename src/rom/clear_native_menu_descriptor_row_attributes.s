; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-descriptor-order.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D308
clear_native_menu_descriptor_row_attributes:
    rep #$30
    .a16
    lda #$0000
    tax
clear_native_menu_descriptor_row_attributes_d0d30e:
    sta a:$18A0,X
    inx
    inx
    .i16
    cpx #$0020
    bcc clear_native_menu_descriptor_row_attributes_d0d30e
    rts
