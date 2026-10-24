; Numeric hold-spell state selectors; docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.segment "CODE"
.org $99F5
sustained_spell_child_dispatch_states:
    .word $9EDA, $9F0D, $9F26
