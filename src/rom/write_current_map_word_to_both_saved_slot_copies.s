; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $56D0
write_current_map_word_to_both_saved_slot_copies:
    rep #$20
    lda f:$000108
    sta f:$3062B9,X
    sta f:$3072B9,X
    sep #$20
    rts
