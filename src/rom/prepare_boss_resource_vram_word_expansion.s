; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

expand_boss_resource_to_vram_low_high = $255E

.segment "CODE"
.org $2534
prepare_boss_resource_vram_word_expansion:
    asl
    asl
    asl
    tax
    sep #$20
    lda f:$D0BC52,X
    sta $7B
    rep #$20
    lda f:$D0BC54,X
    sta $79
    lda f:$D0BC56,X
    sta f:$002116
    lda f:$D0BC58,X
    sta $68
    stz $6A
    stz $6C
    jsr expand_boss_resource_to_vram_low_high
    rts
