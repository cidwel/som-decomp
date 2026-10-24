; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_boss_xor_random_pool = $302C
multiply_boss_terrain_row_stride = $2AA6

.segment "CODE"
.org $300B
draw_boss_frame_random_number:
    sep #$30
    pha
    jsr advance_boss_xor_random_pool
    sta $46
    pla
    beq draw_boss_frame_random_number_c23024
    inc
    sta $4E
    jsr multiply_boss_terrain_row_stride
    lda $57
    rep #$30
    .a16
    and #$00FF
    rts
draw_boss_frame_random_number_c23024:
    lda $46
    rep #$30
    .a16
    and #$00FF
    rts
