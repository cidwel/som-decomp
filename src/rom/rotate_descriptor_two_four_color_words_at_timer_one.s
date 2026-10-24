; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4173
rotate_descriptor_two_four_color_words_at_timer_one:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0001
    bne rotate_descriptor_two_four_color_words_at_timer_one_c2419e
    lda a:$07D8
    sta $95
    lda a:$07DE
    sta a:$07D8
    lda a:$07DC
    sta a:$07DE
    lda a:$07DA
    sta a:$07DC
    lda $95
    sta a:$07DA
    ldx $87
    stz a:$0096,X
rotate_descriptor_two_four_color_words_at_timer_one_c2419e:
    clc
    rts
