; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

select_native_global_or_per_slot_disabled_row_mask = $FD69
test_native_hero_status_against_category_row_mask = $FD46

.segment "CODE"
.org $FD2C
test_native_weapon_owner_state_before_row_mask_dispatch:
    rep #$30
    phx
    lda a:$1844
    sec
    .a16
    sbc #$0180
    tax
    sep #$20
    lda f:$7E0060,X
    plx
    .a8
    cmp #$40
    beq test_native_hero_status_against_category_row_mask
    .a8
    bit #$E0
    bne select_native_global_or_per_slot_disabled_row_mask
