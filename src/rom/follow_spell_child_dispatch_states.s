; Numeric follow-child selectors; docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.segment "CODE"
.org $99CF
follow_spell_child_dispatch_states:
    .word $9A01, $9A3F, $9A54
