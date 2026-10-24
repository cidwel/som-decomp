; Numeric Native7F state selectors; docs/boss-native7f-spells.md.
.setcpu "65816"
.segment "CODE"
.org $9416
native7f_spell_dispatch_targets:
    .word $9424, $9429, $942E, $9433, $9438, $943D, $9442
