; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-hidden-child.md.
.setcpu "65816"
.smart
.a8
.i16

preserve_context_and_initialize_hidden_effect = $00A5

.segment "CODE"
.org $009F
jump_public_hidden_effect_initializer:
    jmp preserve_context_and_initialize_hidden_effect
