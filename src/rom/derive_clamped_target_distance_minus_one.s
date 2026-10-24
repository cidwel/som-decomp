; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three.md.
.setcpu "65816"
.smart
.a8
.i16

derive_low_byte_target_manhattan_distance = $08E3

.segment "CODE"
.org $08BC
derive_clamped_target_distance_minus_one:
    jsr derive_low_byte_target_manhattan_distance
    sta $99
    lsr
    lsr
    lsr
    lsr
    sec
    .a16
    sbc #$0001
    bmi derive_clamped_target_distance_minus_one_c208d1
    .a16
    cmp #$0004
    bcs derive_clamped_target_distance_minus_one_c208d5
    rts
derive_clamped_target_distance_minus_one_c208d1:
    .a16
    lda #$0000
    rts
derive_clamped_target_distance_minus_one_c208d5:
    .a16
    lda #$0004
    rts
