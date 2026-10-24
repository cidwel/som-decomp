; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-hidden-child.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_hidden_effect_global_handle_and_animation017A = $1024

.segment "CODE"
.org $00A5
preserve_context_and_initialize_hidden_effect:
    phb
    phx
    pha
    php
    rep #$10
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    jsr initialize_hidden_effect_global_handle_and_animation017A
    plp
    pla
    plx
    plb
    rtl
