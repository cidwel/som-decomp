; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

apply_native_per_slot_hero_status_row_masks = $FDE4
set_native_inventory_descriptor_disabled_flag = $FE08

.segment "CODE"
.org $FD69
select_native_global_or_per_slot_disabled_row_mask:
    sep #$20
    lda a:$1809
    dec
    dec
    beq apply_native_per_slot_hero_status_row_masks
    rep #$30
    .i16
    ldx #$0000
select_native_global_or_per_slot_disabled_row_mask_d9fd77:
    jsr set_native_inventory_descriptor_disabled_flag
    inx
    inx
    .i16
    cpx #$0020
    bcc select_native_global_or_per_slot_disabled_row_mask_d9fd77
    rts
