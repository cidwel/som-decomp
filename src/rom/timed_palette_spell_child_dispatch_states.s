; Numeric palette-spell state selectors; docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.segment "CODE"
.org $99DB
timed_palette_spell_child_dispatch_states:
    .word $9A01, $9C55, $9C74
