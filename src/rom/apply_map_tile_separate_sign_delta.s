; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A15B
apply_map_tile_separate_sign_delta:
    sep #$30
    lsr $01
    bcs apply_map_tile_separate_sign_delta_c2a16b
    clc
    adc $04
    sta $04
    bcc apply_map_tile_separate_sign_delta_c2a16a
    inc $05
apply_map_tile_separate_sign_delta_c2a16a:
    rts
apply_map_tile_separate_sign_delta_c2a16b:
    .a8
    eor #$3F
    inc
    sta $01
    lda $04
    sec
    sbc $01
    sta $04
    bcs apply_map_tile_separate_sign_delta_c2a17b
    dec $05
apply_map_tile_separate_sign_delta_c2a17b:
    rts
