; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1b91a = $B91A

.segment "CODE"
.org $B8F9
probe_native_detour_tile_up:
    sep #$20
    asl $02
    asl $08
    lda $09
    rol
    dec
    bpl routine_c1b91a
    clc
    adc $9D
    bra routine_c1b91a
