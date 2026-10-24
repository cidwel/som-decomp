; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

classify_boss_direction_by_half_axis_thresholds = $2EF4
derive_boss_direction_quadrant_from_signed_differences = $2EAF
make_boss_direction_differences_absolute_using_c5 = $2ECC
subtract_boss_direction_coordinate_pairs = $2EA0

.segment "CODE"
.org $2E50
derive_eight_way_direction_from_coordinate_pairs:
    jsr subtract_boss_direction_coordinate_pairs
    jsr derive_boss_direction_quadrant_from_signed_differences
    jsr make_boss_direction_differences_absolute_using_c5
    jsr classify_boss_direction_by_half_axis_thresholds
    lda $6A
    lsr
    bcs derive_eight_way_direction_from_coordinate_pairs_c22e69
    .a16
    lda #$0002
    sec
    sbc $6C
    sta $6C
derive_eight_way_direction_from_coordinate_pairs_c22e69:
    lda $6A
    asl
    clc
    adc $6C
    .a16
    cmp #$0008
    bne derive_eight_way_direction_from_coordinate_pairs_c22e76
    lda $C5
derive_eight_way_direction_from_coordinate_pairs_c22e76:
    rts
