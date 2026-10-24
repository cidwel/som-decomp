; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-swap.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_actor_equipment_field_and_restore_index_status = $7A54

.segment "CODE"
.org $77E7
publish_native_inventory_owner_bits_after_equipment_exchange:
    rep #$30
    pha
    clc
    adc a:$1853
    tax
    sep #$20
    jsr read_native_actor_equipment_field_and_restore_index_status
    tyx
    ply
    .a8
    cmp #$15
    bne publish_native_inventory_owner_bits_after_equipment_exchange_c07801
    lda a:$1809
    .a8
    cmp #$03
    bne publish_native_inventory_owner_bits_after_equipment_exchange_c0781b
publish_native_inventory_owner_bits_after_equipment_exchange_c07801:
    lda f:$7ECC00,X
    pha
    rep #$20
    tya
    lsr
    clc
    .a16
    adc #$0100
    lsr
    lsr
    sep #$20
    ora $01,S
    sta $01,S
    pla
    sta f:$7ECC00,X
publish_native_inventory_owner_bits_after_equipment_exchange_c0781b:
    rep #$30
    rts
