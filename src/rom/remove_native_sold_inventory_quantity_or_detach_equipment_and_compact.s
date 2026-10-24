; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-inventory-remove.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_stats_public_jump = $C00036
routine_c07e2a = $7E2A

.segment "CODE"
.org $7DB1
remove_native_sold_inventory_quantity_or_detach_equipment_and_compact:
    rep #$30
    .i16
    ldy #$000B
    ldx a:$183E
    lda f:$7ECC00,X
    .i16
    cpx #$0048
    bcc remove_native_sold_inventory_quantity_or_detach_equipment_and_compact_c07dd4
    sep #$20
    sec
    .a8
    sbc #$20
    sta f:$7ECC00,X
    .a8
    and #$F0
    bne routine_c07e2a
    .i16
    ldy #$000C
    bra remove_native_sold_inventory_quantity_or_detach_equipment_and_compact_c07e01
remove_native_sold_inventory_quantity_or_detach_equipment_and_compact_c07dd4:
    sep #$20
    .a8
    bit #$C0
    beq remove_native_sold_inventory_quantity_or_detach_equipment_and_compact_c07e01
    sec
    .a8
    sbc #$40
    rep #$20
    phx
    phy
    .a16
    and #$00C0
    asl
    asl
    asl
    clc
    adc a:$184F
    tax
    sep #$20
    .a8
    lda #$15
    sta f:$7EE180,X
    rep #$20
    txa
    .a16
    and #$0600
    tax
    jsl f:rebuild_actor_stats_public_jump
    ply
    plx
remove_native_sold_inventory_quantity_or_detach_equipment_and_compact_c07e01:
    sep #$20
    .a8
    lda #$40
    trb a:$1804
    rep #$30
    tya
    clc
    adc a:$1840
    sta a:$1851
