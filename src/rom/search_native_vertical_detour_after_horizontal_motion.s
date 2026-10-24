; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

probe_native_detour_tile_down_with_shared_probe = $B90A
probe_native_detour_tile_up = $B8F9

.segment "CODE"
.org $B877
search_native_vertical_detour_after_horizontal_motion:
    sep #$20
    lda $08
    .a8
    and #$7F
    bit $06
    bmi search_native_vertical_detour_after_horizontal_motion_c1b88a
    inc
    cmp $9C
    bcc search_native_vertical_detour_after_horizontal_motion_c1b890
    sbc $9C
    bra search_native_vertical_detour_after_horizontal_motion_c1b890
search_native_vertical_detour_after_horizontal_motion_c1b88a:
    dec
    bpl search_native_vertical_detour_after_horizontal_motion_c1b890
    clc
    adc $9C
search_native_vertical_detour_after_horizontal_motion_c1b890:
    bit $08
    bpl search_native_vertical_detour_after_horizontal_motion_c1b896
    .a8
    ora #$80
search_native_vertical_detour_after_horizontal_motion_c1b896:
    sta $02
    .a8
    lda #$01
    sta $05
    lda a:$E02E,X
    .a8
    eor #$01
    sta a:$E02E,X
    lsr
    bcs search_native_vertical_detour_after_horizontal_motion_c1b8c8
    jsr probe_native_detour_tile_down_with_shared_probe
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8c2
    inc $05
    jsr probe_native_detour_tile_down_with_shared_probe
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8c2
    inc $05
    jsr probe_native_detour_tile_down_with_shared_probe
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8c2
    inc $05
    jsr probe_native_detour_tile_down_with_shared_probe
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8c2
    rts
search_native_vertical_detour_after_horizontal_motion_c1b8c2:
    sep #$20
    .a8
    lda #$03
    bra search_native_vertical_detour_after_horizontal_motion_c1b8e7
search_native_vertical_detour_after_horizontal_motion_c1b8c8:
    jsr probe_native_detour_tile_up
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8e3
    inc $05
    jsr probe_native_detour_tile_up
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8e3
    inc $05
    jsr probe_native_detour_tile_up
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8e3
    inc $05
    jsr probe_native_detour_tile_up
    bcc search_native_vertical_detour_after_horizontal_motion_c1b8e3
    rts
search_native_vertical_detour_after_horizontal_motion_c1b8e3:
    sep #$20
    .a8
    lda #$83
search_native_vertical_detour_after_horizontal_motion_c1b8e7:
    sta a:$E007,X
    lda $05
    asl
    sta $05
    asl
    adc $05
    clc
    .a8
    adc #$08
    sta a:$E00A,X
    rts
