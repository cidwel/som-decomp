; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

derive_boss_direction_quadrant_from_signed_differences = $2EAF
derive_boss_direction_quadrant_ratio_in_software = $2F1A
make_boss_direction_differences_absolute_using_c5 = $2ECC
subtract_boss_direction_coordinate_pairs = $2EA0

.segment "CODE"
.org $2E77
derive_fine_direction_from_coordinate_pairs:
    jsr subtract_boss_direction_coordinate_pairs
    jsr derive_boss_direction_quadrant_from_signed_differences
    jsr make_boss_direction_differences_absolute_using_c5
    jsr derive_boss_direction_quadrant_ratio_in_software
    lda $6A
    lsr
    bcc derive_fine_direction_from_coordinate_pairs_c22e90
    .a16
    lda #$003F
    sec
    sbc $6C
    sta $6C
derive_fine_direction_from_coordinate_pairs_c22e90:
    lda $6A
    xba
    lsr
    lsr
    clc
    adc $6C
    .a16
    cmp #$0100
    bcc derive_fine_direction_from_coordinate_pairs_c22e9f
    lda $C5
derive_fine_direction_from_coordinate_pairs_c22e9f:
    rts
