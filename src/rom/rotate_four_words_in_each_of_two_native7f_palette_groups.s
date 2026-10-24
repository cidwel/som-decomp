; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $98A1
rotate_four_words_in_each_of_two_native7f_palette_groups:
    lda a:$07BE
    sta $95
    lda a:$07BC
    sta a:$07BE
    lda a:$07BA
    sta a:$07BC
    lda a:$07B8
    sta a:$07BA
    lda $95
    sta a:$07B8
    lda a:$07DE
    sta $95
    lda a:$07DC
    sta a:$07DE
    lda a:$07DA
    sta a:$07DC
    lda a:$07D8
    sta a:$07DA
    lda $95
    sta a:$07D8
    rts
