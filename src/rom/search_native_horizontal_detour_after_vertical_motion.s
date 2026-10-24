; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

probe_native_detour_tile_left = $B810
probe_native_detour_tile_right_with_shared_probe = $B81E

.segment "CODE"
.org $B78D
search_native_horizontal_detour_after_vertical_motion:
    sep #$20
    lda $08
    asl
    sta $02
    lda $09
    rol
    bit $07
    bmi search_native_horizontal_detour_after_vertical_motion_c1b7a4
    inc
    cmp $9D
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7aa
    sbc $9D
    bra search_native_horizontal_detour_after_vertical_motion_c1b7aa
search_native_horizontal_detour_after_vertical_motion_c1b7a4:
    dec
    bpl search_native_horizontal_detour_after_vertical_motion_c1b7aa
    clc
    adc $9D
search_native_horizontal_detour_after_vertical_motion_c1b7aa:
    lsr
    sta $03
    ror $02
    .a8
    lda #$01
    sta $05
    lda a:$E02E,X
    .a8
    eor #$01
    sta a:$E02E,X
    lsr
    bcs search_native_horizontal_detour_after_vertical_motion_c1b7df
    jsr probe_native_detour_tile_right_with_shared_probe
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7d9
    inc $05
    jsr probe_native_detour_tile_right_with_shared_probe
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7d9
    inc $05
    jsr probe_native_detour_tile_right_with_shared_probe
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7d9
    inc $05
    jsr probe_native_detour_tile_right_with_shared_probe
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7d9
    rts
search_native_horizontal_detour_after_vertical_motion_c1b7d9:
    sep #$20
    .a8
    lda #$03
    bra search_native_horizontal_detour_after_vertical_motion_c1b7fe
search_native_horizontal_detour_after_vertical_motion_c1b7df:
    jsr probe_native_detour_tile_left
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7fa
    inc $05
    jsr probe_native_detour_tile_left
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7fa
    inc $05
    jsr probe_native_detour_tile_left
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7fa
    inc $05
    jsr probe_native_detour_tile_left
    bcc search_native_horizontal_detour_after_vertical_motion_c1b7fa
    rts
search_native_horizontal_detour_after_vertical_motion_c1b7fa:
    sep #$20
    .a8
    lda #$83
search_native_horizontal_detour_after_vertical_motion_c1b7fe:
    sta a:$E006,X
    lda $05
    asl
    sta $05
    asl
    adc $05
    clc
    .a8
    adc #$02
    sta a:$E00A,X
    rts
