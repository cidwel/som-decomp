; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-producer.md.
.setcpu "65816"
.smart
.a8
.i16

divide_signed_native_point_delta_into_velocity_and_remainder = $A631
skip_native_point_frame_control_command = $A69C

.segment "CODE"
.org $A4A5
decode_native_frame_point_targets_and_fractional_velocities:
    rep #$20
    .a16
    lda #$00D1
    sta $02
    lda a:$E0FC,X
    sta $00
decode_native_frame_point_targets_and_fractional_velocities_c2a4b1:
    sep #$20
    lda [$00]
    bpl decode_native_frame_point_targets_and_fractional_velocities_c2a4bc
    jsr skip_native_point_frame_control_command
    bra decode_native_frame_point_targets_and_fractional_velocities_c2a4b1
decode_native_frame_point_targets_and_fractional_velocities_c2a4bc:
    rep #$20
    lda [$00]
    sep #$20
    asl
    sta $08
    xba
    rep #$20
    .a16
    and #$00FF
    asl
    adc a:$E06A,X
    sta $10
    lda [$10]
    sta $10
    sep #$20
    stz $01
    lda [$10]
    sta $04
    asl
    asl
    sta $05
    lda $04
    .a8
    and #$0F
    sta $0A
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a4ea
    rts
decode_native_frame_point_targets_and_fractional_velocities_c2a4ea:
    asl
    asl
    rep #$20
    .a16
    and #$00FF
    tax
    inc $10
decode_native_frame_point_targets_and_fractional_velocities_c2a4f4:
    lda [$10]
    .a16
    bit #$0080
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a502
    inc $10
    dex
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a4f4
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a523
decode_native_frame_point_targets_and_fractional_velocities_c2a502:
    inc $10
    inc $10
    .a16
    bit #$0040
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a517
    .a16
    and #$003F
    tay
decode_native_frame_point_targets_and_fractional_velocities_c2a50f:
    dex
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a523
    dey
    bmi decode_native_frame_point_targets_and_fractional_velocities_c2a4f4
    bra decode_native_frame_point_targets_and_fractional_velocities_c2a50f
decode_native_frame_point_targets_and_fractional_velocities_c2a517:
    .a16
    and #$003F
    tay
decode_native_frame_point_targets_and_fractional_velocities_c2a51b:
    dex
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a523
    dey
    bpl decode_native_frame_point_targets_and_fractional_velocities_c2a51b
    bmi decode_native_frame_point_targets_and_fractional_velocities_c2a4f4
decode_native_frame_point_targets_and_fractional_velocities_c2a523:
    rep #$30
    ldx $14
    lda a:$E084,X
    .a16
    and #$000F
    pha
    lda $0A
    .a16
    and #$000F
    tay
    sta $06
    lda $08
    .a16
    and #$00C0
    sta $02
    txa
    lsr
    tax
    pla
    sep #$20
    cmp $0A
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a552
    bcc decode_native_frame_point_targets_and_fractional_velocities_c2a552
    sbc $0A
decode_native_frame_point_targets_and_fractional_velocities_c2a54b:
    inx
    inx
    inx
    inx
    dec
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a54b
decode_native_frame_point_targets_and_fractional_velocities_c2a552:
    rep #$20
    lda [$10]
    inc $10
    inc $10
    sep #$20
    xba
    asl
    ror $01
    xba
    asl
    ror $01
    .a8
    cmp #$80
    bcc decode_native_frame_point_targets_and_fractional_velocities_c2a574
    bit $05
    bvs decode_native_frame_point_targets_and_fractional_velocities_c2a56d
    ror
decode_native_frame_point_targets_and_fractional_velocities_c2a56d:
    clc
    bit $02
    bmi decode_native_frame_point_targets_and_fractional_velocities_c2a57e
    bpl decode_native_frame_point_targets_and_fractional_velocities_c2a583
decode_native_frame_point_targets_and_fractional_velocities_c2a574:
    bit $05
    bvs decode_native_frame_point_targets_and_fractional_velocities_c2a579
    lsr
decode_native_frame_point_targets_and_fractional_velocities_c2a579:
    clc
    bit $02
    bpl decode_native_frame_point_targets_and_fractional_velocities_c2a583
decode_native_frame_point_targets_and_fractional_velocities_c2a57e:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
decode_native_frame_point_targets_and_fractional_velocities_c2a583:
    xba
    bpl decode_native_frame_point_targets_and_fractional_velocities_c2a593
    bit $05
    bvs decode_native_frame_point_targets_and_fractional_velocities_c2a58c
    sec
    ror
decode_native_frame_point_targets_and_fractional_velocities_c2a58c:
    clc
    bit $02
    bvs decode_native_frame_point_targets_and_fractional_velocities_c2a59d
    bvc decode_native_frame_point_targets_and_fractional_velocities_c2a5a2
decode_native_frame_point_targets_and_fractional_velocities_c2a593:
    bit $05
    bvs decode_native_frame_point_targets_and_fractional_velocities_c2a598
    lsr
decode_native_frame_point_targets_and_fractional_velocities_c2a598:
    clc
    bit $02
    bvc decode_native_frame_point_targets_and_fractional_velocities_c2a5a2
decode_native_frame_point_targets_and_fractional_velocities_c2a59d:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
decode_native_frame_point_targets_and_fractional_velocities_c2a5a2:
    rep #$20
    sta a:$C000,X
    inx
    inx
    inx
    inx
    dey
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a552
    ldx $14
    txa
    lsr
    tay
    sep #$20
    lda a:$E084,X
    .a8
    and #$0F
    cmp $0A
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a5c2
    bcs decode_native_frame_point_targets_and_fractional_velocities_c2a5c2
    sta $0A
decode_native_frame_point_targets_and_fractional_velocities_c2a5c2:
    sta a:$C060,Y
    lda a:$E012,X
    sta $00
    asl
    asl
    adc $00
    .a8
    adc #$05
    sta $08
    sta a:$C061,Y
    .a8
    lda #$80
    sta a:$E114,X
    lda a:$C060,Y
    cmp $0A
    beq decode_native_frame_point_targets_and_fractional_velocities_c2a603
    bcc decode_native_frame_point_targets_and_fractional_velocities_c2a603
    sbc $0A
    sta $00
    phx
    phy
decode_native_frame_point_targets_and_fractional_velocities_c2a5e9:
    lda a:$E0D0,X
    sta a:$C000,Y
    lda a:$E0D1,X
    sta a:$C001,Y
    inx
    inx
    inx
    inx
    iny
    iny
    iny
    iny
    dec $00
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a5e9
    ply
    plx
decode_native_frame_point_targets_and_fractional_velocities_c2a603:
    rep #$20
    lda a:$E0D0,X
    sta $00
    lda a:$C000,Y
    jsr divide_signed_native_point_delta_into_velocity_and_remainder
    rep #$20
    sta a:$C000,Y
    lda $02
    sta a:$C002,Y
    sta a:$C032,Y
    lda $00
    sta a:$C030,Y
    sep #$20
    iny
    iny
    iny
    iny
    inx
    inx
    inx
    inx
    dec $0A
    bne decode_native_frame_point_targets_and_fractional_velocities_c2a603
    rts
