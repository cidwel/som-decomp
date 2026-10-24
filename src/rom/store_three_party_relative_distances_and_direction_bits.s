; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0E9B
store_three_party_relative_distances_and_direction_bits:
    stz a:$0052,X
    stz a:$0055,X
    lda a:$002B,X
    sta $46
    lda a:$0032,X
    sta $4E
    .i16
    ldy #$0000
store_three_party_relative_distances_and_direction_bits_c20eae:
    lda $46
    sec
    sbc a:$E002,Y
    bmi store_three_party_relative_distances_and_direction_bits_c20ec7
    .a16
    cmp #$0080
    bcc store_three_party_relative_distances_and_direction_bits_c20ebe
    .a16
    lda #$0080
store_three_party_relative_distances_and_direction_bits_c20ebe:
    sep #$20
    sta a:$0050,X
    rep #$20
    bra store_three_party_relative_distances_and_direction_bits_c20edf
store_three_party_relative_distances_and_direction_bits_c20ec7:
    .a16
    eor #$FFFF
    inc
    .a16
    cmp #$0080
    bcc store_three_party_relative_distances_and_direction_bits_c20ed3
    .a16
    lda #$0080
store_three_party_relative_distances_and_direction_bits_c20ed3:
    sep #$20
    sta a:$0050,X
    .a8
    lda #$80
    sta a:$0052,X
    rep #$20
store_three_party_relative_distances_and_direction_bits_c20edf:
    lda $4E
    sec
    sbc a:$E004,Y
    bmi store_three_party_relative_distances_and_direction_bits_c20ef8
    .a16
    cmp #$0080
    bcc store_three_party_relative_distances_and_direction_bits_c20eef
    .a16
    lda #$0080
store_three_party_relative_distances_and_direction_bits_c20eef:
    sep #$20
    sta a:$0051,X
    rep #$20
    bra store_three_party_relative_distances_and_direction_bits_c20f13
store_three_party_relative_distances_and_direction_bits_c20ef8:
    .a16
    eor #$FFFF
    inc
    .a16
    cmp #$0080
    bcc store_three_party_relative_distances_and_direction_bits_c20f04
    .a16
    lda #$0080
store_three_party_relative_distances_and_direction_bits_c20f04:
    sep #$20
    sta a:$0051,X
    .a8
    lda #$40
    ora a:$0052,X
    sta a:$0052,X
    rep #$20
store_three_party_relative_distances_and_direction_bits_c20f13:
    txa
    clc
    .a16
    adc #$0003
    tax
    tya
    clc
    .a16
    adc #$0200
    tay
    .a16
    cmp #$0600
    bcc store_three_party_relative_distances_and_direction_bits_c20eae
    ldx $87
    rts
