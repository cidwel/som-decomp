; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C5B4
test_charge_effect_contact_geometry_and_mark_target:
    sep #$20
    lda a:$E000,X
    beq test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    bpl test_charge_effect_contact_geometry_and_mark_target_c2c5c1
test_charge_effect_contact_geometry_and_mark_target_c2c5bd:
    sep #$20
    clc
    rts
test_charge_effect_contact_geometry_and_mark_target_c2c5c1:
    lda a:$E00B,X
    eor a:$D001,Y
    bmi test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    lda a:$D000,Y
    .a8
    cmp #$02
    bne test_charge_effect_contact_geometry_and_mark_target_c2c5d4
    .a8
    lda #$20
    bra test_charge_effect_contact_geometry_and_mark_target_c2c5d6
test_charge_effect_contact_geometry_and_mark_target_c2c5d4:
    .a8
    lda #$10
test_charge_effect_contact_geometry_and_mark_target_c2c5d6:
    sta $02
    sta $03
    rep #$20
    lda a:$E0CA,X
    beq test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    clc
    adc $02
    sta $02
    lda a:$E020,X
    sec
    sbc $04
    bpl test_charge_effect_contact_geometry_and_mark_target_c2c5f2
    .a16
    eor #$FFFF
    inc
test_charge_effect_contact_geometry_and_mark_target_c2c5f2:
    .a16
    cmp #$0060
    bcs test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    sep #$20
    asl
    cmp $02
    bcs test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    rep #$20
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    clc
    adc a:$E022,X
    sec
    sbc $06
    bpl test_charge_effect_contact_geometry_and_mark_target_c2c61a
    .a16
    eor #$FFFF
    inc
test_charge_effect_contact_geometry_and_mark_target_c2c61a:
    .a16
    cmp #$0060
    bcs test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    sep #$20
    asl
    cmp $03
    bcs test_charge_effect_contact_geometry_and_mark_target_c2c5bd
    sep #$20
    phx
    pla
    pla
    .a8
    cmp #$06
    bcc test_charge_effect_contact_geometry_and_mark_target_c2c631
    .a8
    sbc #$06
test_charge_effect_contact_geometry_and_mark_target_c2c631:
    .a8
    and #$0F
    bne test_charge_effect_contact_geometry_and_mark_target_c2c637
    .a8
    lda #$01
test_charge_effect_contact_geometry_and_mark_target_c2c637:
    xba
    lda $01
    .a8
    cmp #$06
    bcc test_charge_effect_contact_geometry_and_mark_target_c2c640
    .a8
    sbc #$06
test_charge_effect_contact_geometry_and_mark_target_c2c640:
    .a8
    and #$0F
    bne test_charge_effect_contact_geometry_and_mark_target_c2c646
    .a8
    lda #$01
test_charge_effect_contact_geometry_and_mark_target_c2c646:
    ora a:$E059,X
    sta a:$E059,X
    sec
    rts
