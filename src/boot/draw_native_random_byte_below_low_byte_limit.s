; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-random.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_fifteen_byte_subtractive_random_ring = $C25B
find_native_highest_set_bit_or_byte_ff = $C365

.segment "CODE"
.org $C288
draw_native_random_byte_below_low_byte_limit:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    .a16
    and #$00FF
    bne draw_native_random_byte_below_low_byte_limit_c2a9
    .a16
    lda #$0100
draw_native_random_byte_below_low_byte_limit_c2a9:
    sta $01
    dec
    beq draw_native_random_byte_below_low_byte_limit_c2cd
    tax
    jsr find_native_highest_set_bit_or_byte_ff
    sec
    .a16
    sbc #$0008
    .a16
    eor #$FFFF
    inc
    tay
    .a16
    lda #$01FF
draw_native_random_byte_below_low_byte_limit_c2be:
    lsr
    dey
    bne draw_native_random_byte_below_low_byte_limit_c2be
    sta $03
draw_native_random_byte_below_low_byte_limit_c2c4:
    jsr advance_native_fifteen_byte_subtractive_random_ring
    and $03
    cmp $01
    bcs draw_native_random_byte_below_low_byte_limit_c2c4
draw_native_random_byte_below_low_byte_limit_c2cd:
    plb
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
