; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-visual-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $67AE
rotate_five_native_boss_palette_color_words:
    lda a:$07CE
    sta $95
    lda a:$07D0
    sta a:$07CE
    lda a:$07D2
    sta a:$07D0
    lda a:$07D4
    sta a:$07D2
    lda a:$07D6
    sta a:$07D4
    lda $95
    sta a:$07D6
    rts
