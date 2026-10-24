; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-unused-native-leaves.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $65D9
return_native_clear_carry_without_other_effect:
    clc
    rts
