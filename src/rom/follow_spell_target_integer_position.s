; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $993D
follow_spell_target_integer_position:
    ldy a:$00B2,X
    lda a:$0002,Y
    sta a:$002B,X
    lda a:$0004,Y
    sta a:$0032,X
    rts
