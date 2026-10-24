; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-attributes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D279
publish_native_inventory_owner_and_rotated_selection_attribute:
    php
    rep #$30
    phy
    pha
    phx
    txa
    sec
    sbc a:$182C
    asl
    tay
    sep #$20
    lda f:$7ECC00,X
    pha
    tyx
    lda a:$1809
    .a8
    cmp #$03
    bne publish_native_inventory_owner_and_rotated_selection_attribute_d0d2b5
    ldx a:$182C
    .i16
    ldy #$0000
publish_native_inventory_owner_and_rotated_selection_attribute_d0d29b:
    rep #$20
    txa
    cmp $02,S
    beq publish_native_inventory_owner_and_rotated_selection_attribute_d0d2b0
    sep #$20
    lda f:$7ECC00,X
    inx
    .a8
    cmp #$FF
    beq publish_native_inventory_owner_and_rotated_selection_attribute_d0d29b
    iny
    bra publish_native_inventory_owner_and_rotated_selection_attribute_d0d29b
publish_native_inventory_owner_and_rotated_selection_attribute_d0d2b0:
    rep #$30
    tya
    asl
    tax
publish_native_inventory_owner_and_rotated_selection_attribute_d0d2b5:
    sep #$20
    pla
    .i16
    ldy #$0000
    .a8
    and #$C0
    beq publish_native_inventory_owner_and_rotated_selection_attribute_d0d2e0
    rep #$20
    .a16
    and #$00C0
    asl
    asl
    xba
    tay
    sep #$20
    dec
    cmp a:$1808
    bne publish_native_inventory_owner_and_rotated_selection_attribute_d0d2e0
    .a8
    lda #$02
    bit a:$1803
    bne publish_native_inventory_owner_and_rotated_selection_attribute_d0d2e0
    rep #$30
    txa
    lsr
    sta a:$182E
    bra publish_native_inventory_owner_and_rotated_selection_attribute_d0d2fd
publish_native_inventory_owner_and_rotated_selection_attribute_d0d2e0:
    sep #$20
    .a8
    lda #$02
    bit a:$1803
    beq publish_native_inventory_owner_and_rotated_selection_attribute_d0d2fd
    txa
    lsr
    sec
    sbc a:$182E
    bpl publish_native_inventory_owner_and_rotated_selection_attribute_d0d2f6
    clc
    adc a:$180B
    dec
publish_native_inventory_owner_and_rotated_selection_attribute_d0d2f6:
    rep #$30
    .a16
    and #$00FF
    asl
    tax
publish_native_inventory_owner_and_rotated_selection_attribute_d0d2fd:
    rep #$30
    tya
    sta a:$18A0,X
    plx
    pla
    ply
    plp
    rts
