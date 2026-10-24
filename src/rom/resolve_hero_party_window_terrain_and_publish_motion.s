; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_moving_hero_camera_by_layer = $DA6E
limit_hero_signed_motion_to_live_party_window = $D6C8
routine_c0d74f = $D74F
routine_c0d890 = $D890

.segment "CODE"
.org $D65D
resolve_hero_party_window_terrain_and_publish_motion:
    jsr limit_hero_signed_motion_to_live_party_window
    jsr routine_c0d74f
    bcs resolve_hero_party_window_terrain_and_publish_motion_c0d6b1
    rep #$10
    sep #$20
    ldx $10
    lda $FF
    ora $D0
    bne resolve_hero_party_window_terrain_and_publish_motion_c0d695
    lda a:$E02C,X
    beq resolve_hero_party_window_terrain_and_publish_motion_c0d695
    lda a:$E00E,X
    bmi resolve_hero_party_window_terrain_and_publish_motion_c0d695
    lda $06
    cmp a:$E04C,X
    beq resolve_hero_party_window_terrain_and_publish_motion_c0d688
    sta a:$E04B,X
    sta a:$E04C,X
resolve_hero_party_window_terrain_and_publish_motion_c0d688:
    lda $01
    .a8
    and #$10
    beq resolve_hero_party_window_terrain_and_publish_motion_c0d695
    stx $D4
    .a8
    lda #$80
    sta a:$E04A,X
resolve_hero_party_window_terrain_and_publish_motion_c0d695:
    .a8
    lda #$00
    sta a:$E02D,X
    lda $00
    .a8
    and #$04
    bne resolve_hero_party_window_terrain_and_publish_motion_c0d6a9
    lda $01
    .a8
    and #$07
    beq resolve_hero_party_window_terrain_and_publish_motion_c0d6a9
    sta a:$E08E,X
resolve_hero_party_window_terrain_and_publish_motion_c0d6a9:
    jsr routine_c0d890
    jsr dispatch_moving_hero_camera_by_layer
    clc
    rts
resolve_hero_party_window_terrain_and_publish_motion_c0d6b1:
    rep #$10
    sep #$20
    ldx $10
    lda a:$E02C,X
    ora a:$E00A,X
    bne resolve_hero_party_window_terrain_and_publish_motion_c0d6c6
    lda a:$E02D,X
    inc
    sta a:$E02D,X
resolve_hero_party_window_terrain_and_publish_motion_c0d6c6:
    sec
    rts
