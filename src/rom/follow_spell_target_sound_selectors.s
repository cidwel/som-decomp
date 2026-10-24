; Numeric follow-child selectors; docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.segment "CODE"
.org $E7B9
follow_spell_target_sound_selectors:
    .word $00BB, $00C0, $00BB, $00A9, $00C5, $00C5, $00C5, $00CB
    .word $00CB, $00CB, $0000, $0000, $0000, $0000, $0090, $009B
    .word $0019, $0019, $0019, $0019, $00BB, $00BB, $0000, $0000
    .word $0000, $00BB, $00BB, $00D5, $0000, $0000, $0000
