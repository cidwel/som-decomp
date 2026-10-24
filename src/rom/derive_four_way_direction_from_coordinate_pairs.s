; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

classify_boss_direction_by_larger_absolute_axis = $2EE3
derive_boss_direction_quadrant_from_signed_differences = $2EAF
make_boss_direction_differences_absolute_using_c5 = $2ECC
subtract_boss_direction_coordinate_pairs = $2EA0

.segment "CODE"
.org $2E2A
derive_four_way_direction_from_coordinate_pairs:
    jsr subtract_boss_direction_coordinate_pairs
    jsr derive_boss_direction_quadrant_from_signed_differences
    jsr make_boss_direction_differences_absolute_using_c5
    jsr classify_boss_direction_by_larger_absolute_axis
    lda $6A
    lsr
    bcs derive_four_way_direction_from_coordinate_pairs_c22e43
    .a16
    lda #$0001
    sec
    sbc $6C
    sta $6C
derive_four_way_direction_from_coordinate_pairs_c22e43:
    lda $6A
    clc
    adc $6C
    .a16
    cmp #$0004
    bne derive_four_way_direction_from_coordinate_pairs_c22e4f
    lda $C5
derive_four_way_direction_from_coordinate_pairs_c22e4f:
    rts
