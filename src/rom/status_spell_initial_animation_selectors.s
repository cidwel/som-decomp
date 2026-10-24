; Numeric status-child selectors; docs/boss-native-spell-status-child.md.
.setcpu "65816"
.segment "CODE"
.org $E6FF
status_spell_initial_animation_selectors:
    .word $015D, $015D, $016E, $015F, $0167, $0167, $0167, $0161
    .word $0161, $0161, $016A, $016A, $016A, $016A, $016A, $016A
    .word $0163, $0163, $0163, $0163, $0163, $0166, $0166, $0166
    .word $0166, $016C, $016C, $0000, $0000, $0000, $0126
