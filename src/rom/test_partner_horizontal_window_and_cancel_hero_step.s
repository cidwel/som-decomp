; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D9AE
test_partner_horizontal_window_and_cancel_hero_step:
    sep #$20
    lda a:$E000,X
    beq test_partner_horizontal_window_and_cancel_hero_step_c0d9e2
    bmi test_partner_horizontal_window_and_cancel_hero_step_c0d9e2
    rep #$20
    lda $00
    clc
    bpl test_partner_horizontal_window_and_cancel_hero_step_c0d9c8
    adc a:$E002,X
    bpl test_partner_horizontal_window_and_cancel_hero_step_c0d9d1
    clc
    adc $C0
    bra test_partner_horizontal_window_and_cancel_hero_step_c0d9d1
test_partner_horizontal_window_and_cancel_hero_step_c0d9c8:
    adc a:$E002,X
    cmp $C0
    bcc test_partner_horizontal_window_and_cancel_hero_step_c0d9d1
    sbc $C0
test_partner_horizontal_window_and_cancel_hero_step_c0d9d1:
    sec
    sbc $16
    bcs test_partner_horizontal_window_and_cancel_hero_step_c0d9d8
    adc $C0
test_partner_horizontal_window_and_cancel_hero_step_c0d9d8:
    .a16
    cmp #$0038
    bcc test_partner_horizontal_window_and_cancel_hero_step_c0d9e3
    .a16
    cmp #$00C8
    bcs test_partner_horizontal_window_and_cancel_hero_step_c0d9e3
test_partner_horizontal_window_and_cancel_hero_step_c0d9e2:
    rts
test_partner_horizontal_window_and_cancel_hero_step_c0d9e3:
    sep #$20
    stz $1E
    rts
