; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C44F
reverse_map_graphics_pixel_span_bits:
    rep #$20
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lsr
    rol $00
    lda $00
    sep #$20
    rts
