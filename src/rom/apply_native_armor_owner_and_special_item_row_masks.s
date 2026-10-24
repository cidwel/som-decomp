; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

mark_native_inventory_descriptor_row_at_current_y = $FDFD

.segment "CODE"
.org $FD82
apply_native_armor_owner_and_special_item_row_masks:
    rep #$30
    .i16
    ldx #$0000
    txy
apply_native_armor_owner_and_special_item_row_masks_d9fd88:
    sep #$20
    lda f:$7ECC78
    beq apply_native_armor_owner_and_special_item_row_masks_d9fdb1
    lda f:$7ECC78
    beq apply_native_armor_owner_and_special_item_row_masks_d9fdb1
    lda a:$1808
    bne apply_native_armor_owner_and_special_item_row_masks_d9fda2
    .i16
    cpx #$0001
    beq apply_native_armor_owner_and_special_item_row_masks_d9fdb1
    bra apply_native_armor_owner_and_special_item_row_masks_d9fdd8
apply_native_armor_owner_and_special_item_row_masks_d9fda2:
    .i16
    cpx #$0001
    bne apply_native_armor_owner_and_special_item_row_masks_d9fdb1
    lda f:$7ECC54,X
    .a8
    cmp #$FF
    beq apply_native_armor_owner_and_special_item_row_masks_d9fddd
    bra apply_native_armor_owner_and_special_item_row_masks_d9fdd8
apply_native_armor_owner_and_special_item_row_masks_d9fdb1:
    sep #$20
    lda f:$7ECC54,X
    .a8
    cmp #$FF
    beq apply_native_armor_owner_and_special_item_row_masks_d9fddd
    .a8
    and #$C0
    beq apply_native_armor_owner_and_special_item_row_masks_d9fddb
    phx
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    sec
    .a16
    sbc #$0100
    asl
    tax
    sep #$20
    lda f:$7EE01C,X
    plx
    .a8
    cmp #$00
    beq apply_native_armor_owner_and_special_item_row_masks_d9fddb
apply_native_armor_owner_and_special_item_row_masks_d9fdd8:
    jsr mark_native_inventory_descriptor_row_at_current_y
apply_native_armor_owner_and_special_item_row_masks_d9fddb:
    iny
    iny
apply_native_armor_owner_and_special_item_row_masks_d9fddd:
    inx
    .i16
    cpx #$0008
    bcc apply_native_armor_owner_and_special_item_row_masks_d9fd88
    rts
