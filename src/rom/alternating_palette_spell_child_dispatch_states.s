; Numeric palette-spell state selectors; docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.segment "CODE"
.org $99E7
alternating_palette_spell_child_dispatch_states:
    .word $9A01, $9A3F, $9D64
