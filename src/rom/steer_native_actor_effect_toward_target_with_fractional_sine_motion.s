; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-steering.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8E93
steer_native_actor_effect_toward_target_with_fractional_sine_motion:
    sep #$20
    rep #$20
    lda a:$E074,Y
    .a16
    and #$007F
    clc
    adc a:$E045,Y
    .a16
    eor #$FFFF
    sec
    adc a:$E022,Y
    sec
    sbc $06
    sta $08
    lda a:$E020,Y
    sec
    sbc $04
    sta $0A
    bpl steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ed1
    .a16
    eor #$FFFF
    inc
    sta $0A
    lda $08
    bmi steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ec6
    .a16
    lda #$0040
    bra steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ede
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ec6:
    .a16
    eor #$FFFF
    inc
    sta $08
    .a16
    lda #$0080
    bra steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18eef
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ed1:
    lda $08
    bpl steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18eec
    .a16
    eor #$FFFF
    inc
    sta $08
    .a16
    lda #$00C0
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ede:
    pha
    lda $0A
    pha
    lda $08
    sta $0A
    pla
    sta $08
    pla
    bra steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18eef
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18eec:
    .a16
    lda #$0000
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18eef:
    sta $00
    lda $08
    cmp $0A
    bcc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f06
    pha
    lda $0A
    sta $08
    pla
    sta $0A
    .a16
    lda #$8000
    tsb $00
    lda $08
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f06:
    asl
    asl
    asl
    asl
    sta f:$004204
    sep #$20
    lda $0A
    .a8
    cmp #$18
    bcs steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f18
    clc
    rts
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f18:
    sta f:$004206
    .a8
    eor #$FF
    lsr
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$03
    bcs steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f29
    .a8
    lda #$03
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f29:
    sta $0A
    .a8
    lda #$00
    xba
    lda f:$004214
    .a8
    cmp #$11
    bcc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f38
    .a8
    lda #$10
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f38:
    phx
    tax
    lda $03
    .a8
    cmp #$20
    bcc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f6b
    lda f:$019006,X
    bit $01
    bpl steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f4a
    .a8
    eor #$3F
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f4a:
    ora $00
    sec
    sbc $02
    beq steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f6b
    bpl steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f60
    .a8
    cmp #$FB
    bcs steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f66
    lda $02
    sec
    sbc $0A
    sta $02
    bra steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f6b
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f60:
    .a8
    cmp #$05
    bcc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f67
    lda $0A
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f66:
    clc
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f67:
    adc $02
    sta $02
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f6b:
    lda $03
    sta f:$004202
    rep #$20
    lda $02
    .a16
    and #$003F
    asl
    asl
    asl
    tax
    phy
    .a16
    eor #$01FE
    inc
    inc
    tay
    bit $01
    bvc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f8b
    phy
    phx
    ply
    plx
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18f8b:
    lda f:$00FD22,X
    lsr
    sta $0A
    tyx
    lda f:$00FD22,X
    lsr
    ply
    plx
    sep #$20
    sta f:$004203
    .a8
    lda #$00
    xba
    bit $02
    bpl steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fab
    bvs steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fc1
    bvc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fad
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fab:
    bvc steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fc1
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fad:
    lda f:$004217
    clc
    adc $0C
    sta $0C
    lsr
    lsr
    lsr
    rep #$20
    .a16
    eor #$FFFF
    inc
    bra steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fcf
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fc1:
    lda f:$004217
    clc
    adc $0C
    sta $0C
    lsr
    lsr
    lsr
    rep #$20
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18fcf:
    sta $04
    sep #$20
    lda $0A
    sta f:$004203
    .a8
    lda #$00
    xba
    bit $02
    bpl steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ff4
    lda f:$004217
    clc
    adc $0D
    sta $0D
    lsr
    lsr
    lsr
    rep #$20
    .a16
    eor #$FFFF
    inc
    bra steer_native_actor_effect_toward_target_with_fractional_sine_motion_c19002
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c18ff4:
    lda f:$004217
    clc
    adc $0D
    sta $0D
    lsr
    lsr
    lsr
    rep #$20
steer_native_actor_effect_toward_target_with_fractional_sine_motion_c19002:
    sta $06
    sec
    rts
