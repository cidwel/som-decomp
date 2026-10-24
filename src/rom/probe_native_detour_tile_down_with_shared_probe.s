; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1b83d = $B83D

.segment "CODE"
.org $B90A
probe_native_detour_tile_down_with_shared_probe:
    sep #$20
    asl $02
    asl $08
    lda $09
    rol
    inc
    cmp $9D
    bcc probe_native_detour_tile_down_with_shared_probe_c1b91a
    sbc $9D
probe_native_detour_tile_down_with_shared_probe_c1b91a:
    lsr
    sta $09
    sta $03
    ror $08
    lda $08
    asl
    ror $02
    brl routine_c1b83d
