; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F124
compute_native_wrapped_partner_steering_velocity:
    sep #$10
    rep #$20
    stz $06
    .i8
    ldx #$00
    lda $1C
    sec
    sbc $0C
    bpl compute_native_wrapped_partner_steering_velocity_c0f139
    .i8
    ldx #$80
    .a16
    eor #$FFFF
    inc
compute_native_wrapped_partner_steering_velocity_c0f139:
    asl
    cmp $C0
    bcc compute_native_wrapped_partner_steering_velocity_c0f14b
    sta $00
    txa
    .a16
    eor #$0080
    tax
    lda $C0
    asl
    sec
    sbc $00
compute_native_wrapped_partner_steering_velocity_c0f14b:
    sec
    sbc $18
    bmi compute_native_wrapped_partner_steering_velocity_c0f16a
    beq compute_native_wrapped_partner_steering_velocity_c0f16a
    lsr
    .a16
    cmp #$0004
    sep #$20
    bcc compute_native_wrapped_partner_steering_velocity_c0f162
    lda $16
    .a8
    cmp #$03
    bcs compute_native_wrapped_partner_steering_velocity_c0f162
    .a8
    lda #$03
compute_native_wrapped_partner_steering_velocity_c0f162:
    .i8
    cpx #$80
    bcc compute_native_wrapped_partner_steering_velocity_c0f168
    .a8
    ora #$80
compute_native_wrapped_partner_steering_velocity_c0f168:
    sta $06
compute_native_wrapped_partner_steering_velocity_c0f16a:
    rep #$20
    .i8
    ldx #$00
    lda $1E
    sec
    sbc $0E
    bpl compute_native_wrapped_partner_steering_velocity_c0f17b
    .i8
    ldx #$80
    .a16
    eor #$FFFF
    inc
compute_native_wrapped_partner_steering_velocity_c0f17b:
    asl
    cmp $C2
    bcc compute_native_wrapped_partner_steering_velocity_c0f18d
    sta $00
    txa
    .a16
    eor #$0080
    tax
    lda $C2
    asl
    sec
    sbc $00
compute_native_wrapped_partner_steering_velocity_c0f18d:
    sec
    sbc $1A
    bmi compute_native_wrapped_partner_steering_velocity_c0f1ac
    beq compute_native_wrapped_partner_steering_velocity_c0f1ac
    lsr
    .a16
    cmp #$0004
    sep #$20
    bcc compute_native_wrapped_partner_steering_velocity_c0f1a4
    lda $17
    .a8
    cmp #$03
    bcs compute_native_wrapped_partner_steering_velocity_c0f1a4
    .a8
    lda #$03
compute_native_wrapped_partner_steering_velocity_c0f1a4:
    .i8
    cpx #$80
    bcc compute_native_wrapped_partner_steering_velocity_c0f1aa
    .a8
    ora #$80
compute_native_wrapped_partner_steering_velocity_c0f1aa:
    sta $07
compute_native_wrapped_partner_steering_velocity_c0f1ac:
    sec
    rts
