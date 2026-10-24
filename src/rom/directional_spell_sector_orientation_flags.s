; Numeric projectile-child selectors; docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.segment "CODE"
.org $9B80
directional_spell_sector_orientation_flags:
    .word $0000, $0000, $0000, $0000, $0040, $0040, $0040, $0040
    .word $00C0, $00C0, $00C0, $00C0, $0080, $0080, $0080, $0080
