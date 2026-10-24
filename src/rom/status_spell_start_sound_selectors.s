; Numeric status-child selectors; docs/boss-native-spell-status-child.md.
.setcpu "65816"
.segment "CODE"
.org $E77B
status_spell_start_sound_selectors:
    .word $0083, $0083, $0083, $0083, $0083, $0083, $0083, $0083
    .word $0083, $0083, $0083, $0083, $0083, $0083, $0083, $0083
    .word $0083, $009A, $0083, $0083, $0083, $0083, $0083, $0083
    .word $0083, $0087, $0087, $0000, $00B3, $0000, $00B0
