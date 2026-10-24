; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_inventory_status_masks_by_mode_and_category = $FCC1

.segment "CODE"
.org $FCBD
apply_native_inventory_status_masks_public_wrapper:
    jsr dispatch_native_inventory_status_masks_by_mode_and_category
    rtl
