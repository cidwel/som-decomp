; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FDFC
return_from_native_inventory_mask_category:
    rts
