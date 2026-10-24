; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5EC3
shift_linked_child_signed_word_right_once:
    rol
    php
    ror
    plp
    ror
    rts
