; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

apply_native_armor_owner_and_special_item_row_masks = $FD82
return_from_native_inventory_mask_category = $FDFC
select_native_global_or_per_slot_disabled_row_mask = $FD69

.segment "CODE"
.org $FD46
test_native_hero_status_against_category_row_mask:
    rep #$30
    phx
    ldx a:$1844
    lda f:$7E0010,X
    sta a:$1820
    plx
    lda f:$D9FD12,X
    and a:$1820
    bne select_native_global_or_per_slot_disabled_row_mask
    sep #$20
    lda a:$1809
    .a8
    cmp #$03
    beq apply_native_armor_owner_and_special_item_row_masks
    jmp return_from_native_inventory_mask_category
