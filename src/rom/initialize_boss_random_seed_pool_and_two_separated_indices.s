; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-frame-random-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_boss_terrain_row_stride = $2AA6

.segment "CODE"
.org $3057
initialize_boss_random_seed_pool_and_two_separated_indices:
    sep #$30
    sta a:$033D
    .i8
    ldx #$00
initialize_boss_random_seed_pool_and_two_separated_indices_c2305e:
    lda f:$C2308B,X
    sta a:$0306,X
    inx
    .i8
    cpx #$37
    bne initialize_boss_random_seed_pool_and_two_separated_indices_c2305e
    lda a:$033D
    sta $46
    .a8
    lda #$37
    sta $4E
    jsr multiply_boss_terrain_row_stride
    lda $57
    sta a:$033D
    clc
    .a8
    adc #$1F
    .a8
    cmp #$37
    bcc initialize_boss_random_seed_pool_and_two_separated_indices_c23085
    sec
    .a8
    sbc #$37
initialize_boss_random_seed_pool_and_two_separated_indices_c23085:
    sta a:$033E
    rep #$30
    rts
