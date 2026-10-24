; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-ownership.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7E12
compact_native_equipment_inventory_after_removed_slot:
compact_native_equipment_inventory_after_removed_slot_c07e12:
    sep #$20
    inx
    lda f:$7ECC00,X
    cpx a:$1851
    beq compact_native_equipment_inventory_after_removed_slot_c07e24
    sta f:$7ECBFF,X
    bra compact_native_equipment_inventory_after_removed_slot_c07e12
compact_native_equipment_inventory_after_removed_slot_c07e24:
    .a8
    lda #$FF
    sta f:$7ECBFF,X
    rep #$20
    .a16
    lda #$0000
    rts
