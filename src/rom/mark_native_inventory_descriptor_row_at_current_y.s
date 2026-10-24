; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

set_native_inventory_descriptor_disabled_flag = $FE08

.segment "CODE"
.org $FDFD
mark_native_inventory_descriptor_row_at_current_y:
    phx
    php
    rep #$30
    tyx
    jsr set_native_inventory_descriptor_disabled_flag
    plp
    plx
    rts
