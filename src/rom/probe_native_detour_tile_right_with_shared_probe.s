; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

test_native_partner_detour_tile_attributes = $B84B

.segment "CODE"
.org $B81E
probe_native_detour_tile_right_with_shared_probe:
    sep #$20
    lda $08
    .a8
    and #$7F
    inc
    cmp $9C
    bcc probe_native_detour_tile_right_with_shared_probe_c1b82b
    sbc $9C
probe_native_detour_tile_right_with_shared_probe_c1b82b:
    bit $08
    bpl probe_native_detour_tile_right_with_shared_probe_c1b831
    .a8
    ora #$80
probe_native_detour_tile_right_with_shared_probe_c1b831:
    sta $08
    .a8
    and #$7F
    bit $02
    bpl probe_native_detour_tile_right_with_shared_probe_c1b83b
    .a8
    ora #$80
probe_native_detour_tile_right_with_shared_probe_c1b83b:
    sta $02
    rep #$20
    ldy $02
    jsr test_native_partner_detour_tile_attributes
    bcc probe_native_detour_tile_right_with_shared_probe_c1b847
    rts
probe_native_detour_tile_right_with_shared_probe_c1b847:
    rep #$20
    ldy $08
