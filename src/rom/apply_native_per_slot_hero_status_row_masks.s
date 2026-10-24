; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

set_native_inventory_descriptor_disabled_flag = $FE08

.segment "CODE"
.org $FDE4
apply_native_per_slot_hero_status_row_masks:
    rep #$30
    .i16
    ldx #$0000
apply_native_per_slot_hero_status_row_masks_d9fde9:
    lda f:$D9FE12,X
    and a:$1820
    beq apply_native_per_slot_hero_status_row_masks_d9fdf5
    jsr set_native_inventory_descriptor_disabled_flag
apply_native_per_slot_hero_status_row_masks_d9fdf5:
    inx
    inx
    .i16
    cpx #$000E
    bcc apply_native_per_slot_hero_status_row_masks_d9fde9
