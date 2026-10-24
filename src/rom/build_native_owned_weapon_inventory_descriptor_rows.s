; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-rows.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0d127 = $D127

.segment "CODE"
.org $D128
build_native_owned_weapon_inventory_descriptor_rows:
    lda a:$1808
    .a16
    and #$00FF
    .a16
    ora #$0000
    beq routine_d0d127
    .i16
    ldx #$0000
    .a16
    lda #$0007
build_native_owned_weapon_inventory_descriptor_rows_d0d139:
    pha
    sep #$20
    lda a:$1808
    dec
    bne build_native_owned_weapon_inventory_descriptor_rows_d0d151
    lda f:$7EE3C8,X
    .i16
    cpx #$0006
    bne build_native_owned_weapon_inventory_descriptor_rows_d0d155
    lda f:$7EE3C9,X
    bra build_native_owned_weapon_inventory_descriptor_rows_d0d155
build_native_owned_weapon_inventory_descriptor_rows_d0d151:
    lda f:$7EE5C8,X
build_native_owned_weapon_inventory_descriptor_rows_d0d155:
    inx
    rep #$20
    .a16
    and #$00FF
    beq build_native_owned_weapon_inventory_descriptor_rows_d0d18f
    phx
    txa
    dec
    pha
    asl
    clc
    adc a:$1828
    tax
    lda $01,S
    .a16
    cmp #$0006
    bcc build_native_owned_weapon_inventory_descriptor_rows_d0d184
    inx
    inx
    lda a:$1808
    .a16
    and #$00FF
    .a16
    cmp #$0002
    bne build_native_owned_weapon_inventory_descriptor_rows_d0d184
    lda $01,S
    .a16
    cmp #$0006
    bne build_native_owned_weapon_inventory_descriptor_rows_d0d184
    dex
    dex
build_native_owned_weapon_inventory_descriptor_rows_d0d184:
    lda f:$D8FD60,X
    sta a:$0000,Y
    iny
    iny
    plx
    plx
build_native_owned_weapon_inventory_descriptor_rows_d0d18f:
    pla
    dec
    bne build_native_owned_weapon_inventory_descriptor_rows_d0d139
    lda a:$1874
    tax
    lda a:$1808
    .a16
    and #$00FF
    .a16
    cmp #$0001
    beq build_native_owned_weapon_inventory_descriptor_rows_d0d1a6
    lda a:$1875
    tax
build_native_owned_weapon_inventory_descriptor_rows_d0d1a6:
    txa
    .a16
    and #$00FF
    sta a:$182E
    rts
