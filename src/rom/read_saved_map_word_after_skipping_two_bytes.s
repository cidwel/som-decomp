; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $58EB
read_saved_map_word_after_skipping_two_bytes:
    inx
    inx
    rep #$20
    lda f:$306000,X
    sta f:$000108
    sep #$20
    rts
