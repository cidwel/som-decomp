; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B66E
append_map_graphics_transpose_bits:
    asl
    rol $08
    asl
    rol $09
    asl
    rol $0A
    asl
    rol $0B
    asl
    rol $0C
    asl
    rol $0D
    asl
    rol $0E
    asl
    rol $0F
    rts
