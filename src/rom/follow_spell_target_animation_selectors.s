; Numeric follow-child selectors; docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.segment "CODE"
.org $E73D
follow_spell_target_animation_selectors:
    .word $015E, $016B, $016F, $0160, $0168, $0168, $0168, $0162
    .word $0162, $0162, $0000, $0000, $0000, $0000, $0000, $0000
    .word $0164, $0164, $0164, $0164, $0164, $0000, $0000, $0000
    .word $0000, $016D, $016D, $0165, $0125, $0174, $0127
