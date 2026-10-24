; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-low-nibble-mask.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C34D
derive_sixteen_bit_mask_from_low_nibble:
    phd
    php
    rep #$30
    .a16
    and #$000F
    tax
    .a16
    lda #$0001
    .i16
    cpx #$0000
    beq derive_sixteen_bit_mask_from_low_nibble_c361
derive_sixteen_bit_mask_from_low_nibble_c35d:
    asl
    dex
    bne derive_sixteen_bit_mask_from_low_nibble_c35d
derive_sixteen_bit_mask_from_low_nibble_c361:
    tax
    plp
    pld
    rts
