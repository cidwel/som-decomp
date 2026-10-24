; Numeric hold-spell state selectors; docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.segment "CODE"
.org $99FB
binding_spell_child_dispatch_states:
    .word $9F3C, $9F85, $9FA0
