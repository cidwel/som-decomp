; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A17C
apply_map_tile_signed_six_bit_delta:
    sep #$30
    .a8
    cmp #$20
    bcs apply_map_tile_signed_six_bit_delta_c2a18c
    clc
    adc $04
    sta $04
    bcc apply_map_tile_signed_six_bit_delta_c2a18b
    inc $05
apply_map_tile_signed_six_bit_delta_c2a18b:
    rts
apply_map_tile_signed_six_bit_delta_c2a18c:
    .a8
    eor #$3F
    inc
    sta $01
    lda $04
    sec
    sbc $01
    sta $04
    bcs apply_map_tile_signed_six_bit_delta_c2a19c
    dec $05
apply_map_tile_signed_six_bit_delta_c2a19c:
    rts
