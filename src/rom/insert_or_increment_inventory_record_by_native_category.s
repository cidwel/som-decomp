; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-inventory-command.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $64D1
insert_or_increment_inventory_record_by_native_category:
    rep #$10
    sep #$20
    .i16
    ldy #$0000
    lda a:$1820
    beq insert_or_increment_inventory_record_by_native_category_c06514
    .a8
    cmp #$15
    beq insert_or_increment_inventory_record_by_native_category_c06514
    .a8
    cmp #$2A
    beq insert_or_increment_inventory_record_by_native_category_c06514
    .i16
    ldx #$0024
    .a8
    cmp #$15
    bcc insert_or_increment_inventory_record_by_native_category_c06516
    .i16
    ldx #$0030
    .a8
    cmp #$2A
    bcc insert_or_increment_inventory_record_by_native_category_c06516
    .i16
    ldx #$003C
    .a8
    cmp #$3F
    bcc insert_or_increment_inventory_record_by_native_category_c06516
    sec
    .a8
    sbc #$40
    sta a:$1820
    .i16
    ldx #$0048
    .a8
    cmp #$0C
    bcc insert_or_increment_inventory_record_by_native_category_c0652e
    sec
    .a8
    sbc #$40
    sta a:$1820
    .i16
    ldx #$0054
    .a8
    cmp #$48
    bcc insert_or_increment_inventory_record_by_native_category_c0655f
insert_or_increment_inventory_record_by_native_category_c06514:
    bra insert_or_increment_inventory_record_by_native_category_c0658d
insert_or_increment_inventory_record_by_native_category_c06516:
    lda f:$7ECC00,X
    .a8
    cmp #$FF
    beq insert_or_increment_inventory_record_by_native_category_c06529
    inx
    iny
    .i16
    cpy #$000B
    bcc insert_or_increment_inventory_record_by_native_category_c06516
    .a8
    lda #$01
    bra insert_or_increment_inventory_record_by_native_category_c0658f
insert_or_increment_inventory_record_by_native_category_c06529:
    lda a:$1820
    bra insert_or_increment_inventory_record_by_native_category_c0657a
insert_or_increment_inventory_record_by_native_category_c0652e:
    stz a:$1821
    lda f:$7ECC00,X
    .a8
    cmp #$FF
    beq insert_or_increment_inventory_record_by_native_category_c0654b
    .a8
    and #$1F
    cmp a:$1820
    beq insert_or_increment_inventory_record_by_native_category_c06552
    inx
    iny
    .i16
    cpy #$000C
    bcc insert_or_increment_inventory_record_by_native_category_c0652e
insert_or_increment_inventory_record_by_native_category_c06547:
    .a8
    lda #$02
    bra insert_or_increment_inventory_record_by_native_category_c0658f
insert_or_increment_inventory_record_by_native_category_c0654b:
    lda a:$1820
    .a8
    ora #$20
    bra insert_or_increment_inventory_record_by_native_category_c0657a
insert_or_increment_inventory_record_by_native_category_c06552:
    lda f:$7ECC00,X
    clc
    .a8
    adc #$20
    .a8
    cmp #$9F
    bcs insert_or_increment_inventory_record_by_native_category_c06547
    bra insert_or_increment_inventory_record_by_native_category_c0657a
insert_or_increment_inventory_record_by_native_category_c0655f:
    sec
    .a8
    sbc #$09
    bmi insert_or_increment_inventory_record_by_native_category_c06567
    inx
    bra insert_or_increment_inventory_record_by_native_category_c0655f
insert_or_increment_inventory_record_by_native_category_c06567:
    clc
    .a8
    adc #$09
    sta a:$1820
    lda f:$7ECC00,X
    .a8
    cmp #$FF
    beq insert_or_increment_inventory_record_by_native_category_c06529
    .a8
    and #$C0
    ora a:$1820
insert_or_increment_inventory_record_by_native_category_c0657a:
    pha
    lda a:$1821
    asl
    asl
    asl
    asl
    asl
    asl
    ora $01,S
    sta $01,S
    pla
    sta f:$7ECC00,X
insert_or_increment_inventory_record_by_native_category_c0658d:
    .a8
    lda #$00
insert_or_increment_inventory_record_by_native_category_c0658f:
    sta f:$7ECF0F
    rts
