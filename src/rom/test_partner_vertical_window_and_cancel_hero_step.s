; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DA34
test_partner_vertical_window_and_cancel_hero_step:
    sep #$20
    lda a:$E000,X
    beq test_partner_vertical_window_and_cancel_hero_step_c0da68
    bmi test_partner_vertical_window_and_cancel_hero_step_c0da68
    rep #$20
    lda $00
    clc
    bpl test_partner_vertical_window_and_cancel_hero_step_c0da4e
    adc a:$E004,X
    bpl test_partner_vertical_window_and_cancel_hero_step_c0da57
    clc
    adc $C2
    bra test_partner_vertical_window_and_cancel_hero_step_c0da57
test_partner_vertical_window_and_cancel_hero_step_c0da4e:
    adc a:$E004,X
    cmp $C2
    bcc test_partner_vertical_window_and_cancel_hero_step_c0da57
    sbc $C2
test_partner_vertical_window_and_cancel_hero_step_c0da57:
    sec
    sbc $18
    bcs test_partner_vertical_window_and_cancel_hero_step_c0da5e
    adc $C2
test_partner_vertical_window_and_cancel_hero_step_c0da5e:
    .a16
    cmp #$0048
    bcc test_partner_vertical_window_and_cancel_hero_step_c0da69
    .a16
    cmp #$00B0
    bcs test_partner_vertical_window_and_cancel_hero_step_c0da69
test_partner_vertical_window_and_cancel_hero_step_c0da68:
    rts
test_partner_vertical_window_and_cancel_hero_step_c0da69:
    sep #$20
    stz $1F
    rts
