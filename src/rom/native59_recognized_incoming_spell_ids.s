; Numeric Native59 spell and attack selectors; docs/boss-native59-actions.md.
.setcpu "65816"
.segment "CODE"
.org $86A5
native59_recognized_incoming_spell_ids:
    .byte $01, $00, $06, $08, $0D, $0C, $13, $12
    .byte $1F, $28
