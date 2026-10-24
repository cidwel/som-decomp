; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

select_target_and_heading_from_linked_child_fractional_tip = $5D87

.segment "CODE"
.org $5C06
refresh_linked_child_target_heading_and_return:
    jsr select_target_and_heading_from_linked_child_fractional_tip
    clc
    rts
