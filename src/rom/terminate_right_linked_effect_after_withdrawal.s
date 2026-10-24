; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-linked-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $842C
terminate_right_linked_effect_after_withdrawal:
    sec
    rts
