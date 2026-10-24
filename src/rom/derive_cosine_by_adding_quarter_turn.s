; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A59
derive_cosine_by_adding_quarter_turn:
    sep #$20
    xba
    inc
    xba
    rep #$20
