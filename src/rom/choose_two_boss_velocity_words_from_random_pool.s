; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $61B1
choose_two_boss_velocity_words_from_random_pool:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    dec
    sta $95
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    dec
    sta $97
    ldx $87
    lda $95
    sta a:$003C,X
    lda $97
    sta a:$0040,X
    rts
