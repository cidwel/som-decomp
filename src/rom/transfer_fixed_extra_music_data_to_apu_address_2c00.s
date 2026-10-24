; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-music-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $067E
transfer_fixed_extra_music_data_to_apu_address_2c00:
    php
    sep #$20
    .i16
    ldx #$2C00
    stx a:$2142
    xba
    sta a:$2140
transfer_fixed_extra_music_data_to_apu_address_2c00_c3068b:
    cmp a:$2140
    bne transfer_fixed_extra_music_data_to_apu_address_2c00_c3068b
    inc
    xba
    .i16
    ldx #$0000
    lda f:$C32137
    sta $10
    lda f:$C32138
    sta $11
transfer_fixed_extra_music_data_to_apu_address_2c00_c306a1:
    lda f:$C32139,X
    sta a:$2142
    lda f:$C3213A,X
    sta a:$2143
    inx
    inx
    xba
    sta a:$2140
transfer_fixed_extra_music_data_to_apu_address_2c00_c306b5:
    cmp a:$2140
    bne transfer_fixed_extra_music_data_to_apu_address_2c00_c306b5
    inc
    bne transfer_fixed_extra_music_data_to_apu_address_2c00_c306be
    inc
transfer_fixed_extra_music_data_to_apu_address_2c00_c306be:
    xba
    cpx $10
    bne transfer_fixed_extra_music_data_to_apu_address_2c00_c306a1
    .a8
    lda #$00
    xba
    plp
    rts
