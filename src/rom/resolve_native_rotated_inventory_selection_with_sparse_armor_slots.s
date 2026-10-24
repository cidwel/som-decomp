; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7635
resolve_native_rotated_inventory_selection_with_sparse_armor_slots:
    sep #$20
    rep #$10
    phx
    clc
    adc a:$182E
    tax
    cmp a:$180B
    bcc resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c07651
    sec
    sbc a:$180B
    tax
    lda a:$1809
    .a8
    cmp #$04
    bcc resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c07651
    inx
resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c07651:
    lda a:$1809
    .a8
    cmp #$03
    bne resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c0767c
    phx
    sep #$10
    txy
    rep #$10
    ldx a:$186A
resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c07661:
    lda f:$7ECC00,X
    inx
    .a8
    cmp #$FF
    beq resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c07661
    dey
    bpl resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c07661
    dex
    rep #$20
    txa
    sec
    sbc a:$1820
    sta $01,S
    sep #$20
    plx
    bra resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c0768a
resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c0767c:
    .a8
    cmp #$04
    bcc resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c0768a
    txa
    inc
    cmp a:$180B
    bne resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c0768a
    .i16
    ldx #$0000
resolve_native_rotated_inventory_selection_with_sparse_armor_slots_c0768a:
    txa
    rep #$30
    .a16
    and #$00FF
    clc
    adc a:$1820
    sta a:$182C
    plx
    rts
