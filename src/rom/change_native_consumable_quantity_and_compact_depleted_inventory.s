; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-action-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $78C3
change_native_consumable_quantity_and_compact_depleted_inventory:
    php
    sep #$30
    .i8
    ldy #$20
    .a8
    ora #$00
    bpl change_native_consumable_quantity_and_compact_depleted_inventory_c078ce
    .i8
    ldy #$E0
change_native_consumable_quantity_and_compact_depleted_inventory_c078ce:
    phy
    lda f:$7ECC48,X
    tay
    clc
    adc $01,S
    .a8
    and #$E0
    sta $01,S
    tya
    .a8
    and #$1F
    ora $01,S
    sta f:$7ECC48,X
    .a8
    and #$E0
    bne change_native_consumable_quantity_and_compact_depleted_inventory_c07905
change_native_consumable_quantity_and_compact_depleted_inventory_c078e8:
    .i8
    cpx #$0B
    bcs change_native_consumable_quantity_and_compact_depleted_inventory_c078f7
    lda f:$7ECC49,X
    sta f:$7ECC48,X
    inx
    bra change_native_consumable_quantity_and_compact_depleted_inventory_c078e8
change_native_consumable_quantity_and_compact_depleted_inventory_c078f7:
    .a8
    lda #$FF
    sta f:$7ECC48,X
    dec a:$1873
    bpl change_native_consumable_quantity_and_compact_depleted_inventory_c07905
    stz a:$1873
change_native_consumable_quantity_and_compact_depleted_inventory_c07905:
    ply
    plp
    rtl
