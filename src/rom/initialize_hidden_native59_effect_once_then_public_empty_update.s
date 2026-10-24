; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-hidden-child.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_hidden_effect_empty_update = $C000A2
jump_public_hidden_effect_initializer = $C0009F

.segment "CODE"
.org $3D34
initialize_hidden_native59_effect_once_then_public_empty_update:
    lda a:$0094,X
    bne initialize_hidden_native59_effect_once_then_public_empty_update_c23d42
    inc a:$0094,X
    jsl f:jump_public_hidden_effect_initializer
    clc
    rts
initialize_hidden_native59_effect_once_then_public_empty_update_c23d42:
    jsl f:jump_public_hidden_effect_empty_update
    clc
    rts
