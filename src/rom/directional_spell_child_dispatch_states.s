; Numeric projectile-child selectors; docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.segment "CODE"
.org $99D5
directional_spell_child_dispatch_states:
    .word $9A01, $9AE5, $9C47
