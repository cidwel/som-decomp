; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D962
test_hero_horizontal_step_against_camera_window:
    sep #$30
    lda $1E
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$007F
    bcs test_hero_horizontal_step_against_camera_window_c0d97b
    sta $00
    adc $12
    cmp $C0
    bcc test_hero_horizontal_step_against_camera_window_c0d989
    sbc $C0
    bra test_hero_horizontal_step_against_camera_window_c0d989
test_hero_horizontal_step_against_camera_window_c0d97b:
    .a16
    eor #$FFFF
    inc
    sta $00
    clc
    adc $12
    bpl test_hero_horizontal_step_against_camera_window_c0d989
    clc
    adc $C0
test_hero_horizontal_step_against_camera_window_c0d989:
    sec
    sbc $16
    bcs test_hero_horizontal_step_against_camera_window_c0d990
    adc $C0
test_hero_horizontal_step_against_camera_window_c0d990:
    bit $1D
    bmi test_hero_horizontal_step_against_camera_window_c0d99b
    .a16
    cmp #$00C8
    bcs test_hero_horizontal_step_against_camera_window_c0d9a2
    clc
    rts
test_hero_horizontal_step_against_camera_window_c0d99b:
    .a16
    cmp #$0038
    bcc test_hero_horizontal_step_against_camera_window_c0d9a2
    clc
    rts
test_hero_horizontal_step_against_camera_window_c0d9a2:
    rep #$20
    lda $00
    .a16
    eor #$FFFF
    inc
    sta $00
    sec
    rts
