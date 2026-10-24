; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-random.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C365
find_native_highest_set_bit_or_byte_ff:
    phd
    php
    rep #$30
    txa
    .i16
    ldx #$0010
find_native_highest_set_bit_or_byte_ff_c36d:
    asl
    bcs find_native_highest_set_bit_or_byte_ff_c378
    dex
    bne find_native_highest_set_bit_or_byte_ff_c36d
    .a16
    lda #$00FF
    bra find_native_highest_set_bit_or_byte_ff_c37a
find_native_highest_set_bit_or_byte_ff_c378:
    txa
    dec
find_native_highest_set_bit_or_byte_ff_c37a:
    plp
    pld
    rts
