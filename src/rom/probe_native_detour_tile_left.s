; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1b82b = $B82B

.segment "CODE"
.org $B810
probe_native_detour_tile_left:
    sep #$20
    lda $08
    .a8
    and #$7F
    dec
    bpl routine_c1b82b
    clc
    adc $9C
    bra routine_c1b82b
