; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-descriptor-sources.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D263
append_native_menu_descriptor_from_category_table:
    phx
    asl
    clc
    adc a:$1828
    tax
    lda f:$D8FD60,X
    sta a:$0000,Y
    iny
    iny
    plx
    rts
