; Recovered Secret of Mana USA routine; behaviour documented in docs/map-tile-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00cb8c = $CB8C

.segment "CODE"
.org $803D
refresh_map_tiles_preserving_cpu_context:
    php
    phb
    phd
    rep #$20
    .a16
    lda #$0000
    tcd
    sep #$20
    pha
    plb
    jsl f:routine_00cb8c
    pld
    plb
    plp
    rtl
