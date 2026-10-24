; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-unused-native-leaves.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $65DB
return_native_without_other_effect:
    rts
