; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5B0E
return_linked_child_periodic_idle_carry_clear:
    clc
    rts
