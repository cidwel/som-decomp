; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $4F22
turn_body_heading_one_step_toward_target_with_opposite_rng_tie:
    ldx $87
    sta $95
    lda a:$00BA,X
    sta $97
    lda $95
    sec
    sbc $97
    beq turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f5d
    bmi turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f45
    .a16
    cmp #$0004
    beq turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f61
    bcc turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f54
    lda $97
    clc
    .a16
    adc #$0008
    sta $97
    bra turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f54
turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f45:
    .a16
    cmp #$FFFC
    beq turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f61
    bcs turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f54
    lda $95
    clc
    .a16
    adc #$0008
    sta $95
turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f54:
    lda $95
    sec
    sbc $97
    bmi turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f69
    bra turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f73
turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f5d:
    lda a:$00BA,X
    rts
turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f61:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    beq turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f73
turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f69:
    ldx $87
    lda a:$00BA,X
    dec
    .a16
    and #$0007
    rts
turn_body_heading_one_step_toward_target_with_opposite_rng_tie_c24f73:
    ldx $87
    lda a:$00BA,X
    inc
    .a16
    and #$0007
    rts
