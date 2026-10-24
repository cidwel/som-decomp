; Recovered Secret of Mana USA routine; behaviour documented in docs/latent-inventory-compaction.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7F25
compact_latent_equipment_inventory_after_removed_slot:
compact_latent_equipment_inventory_after_removed_slot_c07f25:
    sep #$20
    inx
    lda f:$7ECC00,X
    cpx a:$1851
    beq compact_latent_equipment_inventory_after_removed_slot_c07f37
    sta f:$7ECBFF,X
    bra compact_latent_equipment_inventory_after_removed_slot_c07f25
compact_latent_equipment_inventory_after_removed_slot_c07f37:
    .a8
    lda #$FF
    sta f:$7ECBFF,X
    rep #$20
    .a16
    lda #$0000
    rts
