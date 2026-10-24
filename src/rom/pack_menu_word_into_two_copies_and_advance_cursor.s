; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $579F
pack_menu_word_into_two_copies_and_advance_cursor:
    rep #$20
    lda a:$A25A
    sta f:$306000,X
    sta f:$307000,X
    inx
    inx
    sep #$20
    rts
