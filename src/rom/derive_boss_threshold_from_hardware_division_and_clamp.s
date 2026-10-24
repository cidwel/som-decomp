; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-target-animation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5920
derive_boss_threshold_from_hardware_division_and_clamp:
    lda a:$0184,X
    sta f:$004204
    sep #$20
    lda a:$0042,X
    bne derive_boss_threshold_from_hardware_division_and_clamp_c25932
    .a8
    lda #$02
    bra derive_boss_threshold_from_hardware_division_and_clamp_c25934
derive_boss_threshold_from_hardware_division_and_clamp_c25932:
    .a8
    lda #$06
derive_boss_threshold_from_hardware_division_and_clamp_c25934:
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    rep #$20
    lda a:$0182,X
    sec
    sbc f:$004214
    bpl derive_boss_threshold_from_hardware_division_and_clamp_c2594d
    .a16
    lda #$0000
derive_boss_threshold_from_hardware_division_and_clamp_c2594d:
    sta a:$00BE,X
    rts
