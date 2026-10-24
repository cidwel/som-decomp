; Numeric status-child selectors; docs/boss-native-spell-status-child.md.
.setcpu "65816"
.segment "CODE"
.org $99E1
status_spell_child_dispatch_states:
    .word $9A01, $9CB6, $9D26
