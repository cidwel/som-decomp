; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-hidden-child.md.
.setcpu "65816"
.smart
.a8
.i16

return_from_public_hidden_effect_update = $00B9

.segment "CODE"
.org $00A2
jump_public_hidden_effect_empty_update:
    jmp return_from_public_hidden_effect_update
