; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-ownership.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $76CC
remove_native_inventory_owner_and_return_owner_bits:
    php
    sep #$30
    stz a:$1820
    inc a:$1820
    inc
    rep #$20
    xba
    lsr
    lsr
    .a16
    and #$00C0
    sep #$20
    pha
    ldx a:$186A
    .i8
    ldy #$0B
    lda a:$1809
    .a8
    cmp #$03
    bne remove_native_inventory_owner_and_return_owner_bits_c076ef
    .i8
    ldy #$08
remove_native_inventory_owner_and_return_owner_bits_c076ef:
    lda f:$7ECC00,X
    .a8
    cmp #$FF
    beq remove_native_inventory_owner_and_return_owner_bits_c076fd
    .a8
    and #$C0
    cmp $01,S
    beq remove_native_inventory_owner_and_return_owner_bits_c07703
remove_native_inventory_owner_and_return_owner_bits_c076fd:
    inx
    dey
    bne remove_native_inventory_owner_and_return_owner_bits_c076ef
    bra remove_native_inventory_owner_and_return_owner_bits_c07712
remove_native_inventory_owner_and_return_owner_bits_c07703:
    lda a:$1820
    beq remove_native_inventory_owner_and_return_owner_bits_c07712
    lda f:$7ECC00,X
    .a8
    and #$3F
    sta f:$7ECC00,X
remove_native_inventory_owner_and_return_owner_bits_c07712:
    pla
    plp
    rts
