; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FE08
set_native_inventory_descriptor_disabled_flag:
    lda a:$18A0,X
    .a16
    ora #$4000
    sta a:$18A0,X
    rts
