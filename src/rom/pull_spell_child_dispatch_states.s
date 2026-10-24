; Numeric pull-spell state selectors; docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.segment "CODE"
.org $99ED
pull_spell_child_dispatch_states:
    .word $9D93, $9DC6, $9DDF, $9E44
