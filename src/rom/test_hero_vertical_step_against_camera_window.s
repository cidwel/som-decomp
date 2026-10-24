; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D9E8
test_hero_vertical_step_against_camera_window:
    sep #$30
    lda $1F
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs test_hero_vertical_step_against_camera_window_c0da01
    sta $00
    adc $14
    cmp $C2
    bcc test_hero_vertical_step_against_camera_window_c0da0f
    sbc $C2
    bra test_hero_vertical_step_against_camera_window_c0da0f
test_hero_vertical_step_against_camera_window_c0da01:
    .a16
    eor #$FFFF
    inc
    sta $00
    clc
    adc $14
    bpl test_hero_vertical_step_against_camera_window_c0da0f
    clc
    adc $C2
test_hero_vertical_step_against_camera_window_c0da0f:
    sec
    sbc $18
    bcs test_hero_vertical_step_against_camera_window_c0da16
    adc $C2
test_hero_vertical_step_against_camera_window_c0da16:
    bit $1E
    bmi test_hero_vertical_step_against_camera_window_c0da21
    .a16
    cmp #$00B0
    bcs test_hero_vertical_step_against_camera_window_c0da28
    clc
    rts
test_hero_vertical_step_against_camera_window_c0da21:
    .a16
    cmp #$0048
    bcc test_hero_vertical_step_against_camera_window_c0da28
    clc
    rts
test_hero_vertical_step_against_camera_window_c0da28:
    rep #$20
    lda $00
    .a16
    eor #$FFFF
    inc
    sta $00
    sec
    rts
