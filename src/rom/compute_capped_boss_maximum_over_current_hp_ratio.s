; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_word_by_word_in_software = $2CBF

.segment "CODE"
.org $09B4
compute_capped_boss_maximum_over_current_hp_ratio:
    ldx $87
    lda a:$0190,X
    bpl compute_capped_boss_maximum_over_current_hp_ratio_c209be
    lda $C5
    rts
compute_capped_boss_maximum_over_current_hp_ratio_c209be:
    lda a:$0182,X
    sta $4E
    lda a:$0184,X
    sta $46
    jsr divide_unsigned_word_by_word_in_software
    lda $56
    .a16
    cmp #$0004
    bcc compute_capped_boss_maximum_over_current_hp_ratio_c209d5
    .a16
    lda #$0004
compute_capped_boss_maximum_over_current_hp_ratio_c209d5:
    rts
