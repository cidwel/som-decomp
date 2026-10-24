; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

cache_nearest_colour_sample = $86F1
quantize_component_cube_index = $83E2

.segment "CODE"
.org $87C9
lookup_cached_colour_sample:
    phd
    php
    rep #$30
    sep #$20
    txy
    jsr quantize_component_cube_index
    lda f:$7F8000,X
    bne lookup_cached_colour_sample_87dc
    jsr cache_nearest_colour_sample
lookup_cached_colour_sample_87dc:
    plp
    pld
    rts
