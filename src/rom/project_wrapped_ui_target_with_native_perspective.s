; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_ui_target_pair_in_first_coefficient_order = $B444
multiply_ui_target_pair_in_second_coefficient_order = $B435

.segment "CODE"
.org $B287
project_wrapped_ui_target_with_native_perspective:
    rep #$30
    lda $FA
    .a16
    and #$0FFF
    sta $00
    lda $FC
    .a16
    and #$0FFF
    sta $02
    lda $0C
    sec
    sbc $00
    bpl project_wrapped_ui_target_with_native_perspective_c2b2a8
    .a16
    cmp #$F801
    bcs project_wrapped_ui_target_with_native_perspective_c2b2b0
    .a16
    adc #$1000
    bra project_wrapped_ui_target_with_native_perspective_c2b2b0
project_wrapped_ui_target_with_native_perspective_c2b2a8:
    .a16
    cmp #$0800
    bcc project_wrapped_ui_target_with_native_perspective_c2b2b0
    .a16
    sbc #$1000
project_wrapped_ui_target_with_native_perspective_c2b2b0:
    sta $0C
    lda $0E
    sec
    sbc $02
    bpl project_wrapped_ui_target_with_native_perspective_c2b2c3
    .a16
    cmp #$F801
    bcs project_wrapped_ui_target_with_native_perspective_c2b2cb
    .a16
    adc #$1000
    bra project_wrapped_ui_target_with_native_perspective_c2b2cb
project_wrapped_ui_target_with_native_perspective_c2b2c3:
    .a16
    cmp #$0800
    bcc project_wrapped_ui_target_with_native_perspective_c2b2cb
    .a16
    sbc #$1000
project_wrapped_ui_target_with_native_perspective_c2b2cb:
    sta $0E
    lda $F6
    .a16
    and #$00FF
    asl
    tay
    .a16
    eor #$01FE
    inc
    inc
    tax
    .a16
    lda #$0100
    bit $F6
    beq project_wrapped_ui_target_with_native_perspective_c2b2e5
    phy
    phx
    ply
    plx
project_wrapped_ui_target_with_native_perspective_c2b2e5:
    lda a:$FD22,Y
    sta $02
    lda a:$FD22,X
    sta $04
    sep #$20
    lda $03
    beq project_wrapped_ui_target_with_native_perspective_c2b307
    lda $04
    sta a:$4202
    jsr multiply_ui_target_pair_in_first_coefficient_order
    ldx $0C
    stx $00
    ldx $0E
    stx $04
    bra project_wrapped_ui_target_with_native_perspective_c2b32e
project_wrapped_ui_target_with_native_perspective_c2b307:
    lda $05
    beq project_wrapped_ui_target_with_native_perspective_c2b31d
    lda $02
    sta a:$4202
    jsr multiply_ui_target_pair_in_second_coefficient_order
    ldx $0C
    stx $02
    ldx $0E
    stx $06
    bra project_wrapped_ui_target_with_native_perspective_c2b32e
project_wrapped_ui_target_with_native_perspective_c2b31d:
    lda $04
    sta a:$4202
    ldy $02
    jsr multiply_ui_target_pair_in_first_coefficient_order
    tya
    sta a:$4202
    jsr multiply_ui_target_pair_in_second_coefficient_order
project_wrapped_ui_target_with_native_perspective_c2b32e:
    rep #$20
    lda $F7
    lsr
    bcc project_wrapped_ui_target_with_native_perspective_c2b358
    lsr
    bcs project_wrapped_ui_target_with_native_perspective_c2b34a
    lda $02
    clc
    adc $04
    .a16
    eor #$FFFF
    inc
    sta $02
    lda $00
    sec
    sbc $06
    bra project_wrapped_ui_target_with_native_perspective_c2b379
project_wrapped_ui_target_with_native_perspective_c2b34a:
    lda $02
    clc
    adc $04
    sta $02
    lda $06
    sec
    sbc $00
    bra project_wrapped_ui_target_with_native_perspective_c2b379
project_wrapped_ui_target_with_native_perspective_c2b358:
    lsr
    bcc project_wrapped_ui_target_with_native_perspective_c2b36d
    lda $04
    sec
    sbc $02
    sta $02
    lda $06
    clc
    adc $00
    .a16
    eor #$FFFF
    inc
    bra project_wrapped_ui_target_with_native_perspective_c2b379
project_wrapped_ui_target_with_native_perspective_c2b36d:
    lda $02
    sec
    sbc $04
    sta $02
    lda $06
    clc
    adc $00
project_wrapped_ui_target_with_native_perspective_c2b379:
    sta $04
    bmi project_wrapped_ui_target_with_native_perspective_c2b37f
project_wrapped_ui_target_with_native_perspective_c2b37d:
    sec
    rts
project_wrapped_ui_target_with_native_perspective_c2b37f:
    .a16
    eor #$FFFF
    inc
    .a16
    cmp #$0200
    bcs project_wrapped_ui_target_with_native_perspective_c2b37d
    .a16
    cmp #$0008
    bcc project_wrapped_ui_target_with_native_perspective_c2b37d
    lsr
    sta $09
    lda $02
    bpl project_wrapped_ui_target_with_native_perspective_c2b398
    .a16
    eor #$FFFF
    inc
project_wrapped_ui_target_with_native_perspective_c2b398:
    .a16
    cmp #$0150
    bcs project_wrapped_ui_target_with_native_perspective_c2b37d
    lsr
    sta $00
    lsr
    lsr
    .a16
    eor #$FFFF
    sec
    adc $00
    xba
    sta a:$4204
    sep #$20
    lda $09
    .a8
    eor #$FF
    inc
    lsr
    lsr
    lsr
    adc $09
    sta a:$4206
    rep #$20
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda a:$4214
    .a16
    cmp #$0080
    bcs project_wrapped_ui_target_with_native_perspective_c2b37d
    sep #$20
    clc
    bit $03
    bpl project_wrapped_ui_target_with_native_perspective_c2b3d6
    .a8
    eor #$FF
project_wrapped_ui_target_with_native_perspective_c2b3d6:
    .a8
    adc #$80
    sta $08
    stz $0A
    lda $F8
    sec
    sbc $0B
    bcs project_wrapped_ui_target_with_native_perspective_c2b3e8
    .a8
    eor #$FF
    inc
    dec $0A
project_wrapped_ui_target_with_native_perspective_c2b3e8:
    stz a:$4204
    lsr
    lsr
    lsr
    sta a:$4205
    lda $09
    sta a:$4206
    rep #$20
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda a:$4214
    .a16
    cmp #$0080
    bcc project_wrapped_ui_target_with_native_perspective_c2b40a
project_wrapped_ui_target_with_native_perspective_c2b408:
    sec
    rts
project_wrapped_ui_target_with_native_perspective_c2b40a:
    sep #$20
    bit $0A
    bpl project_wrapped_ui_target_with_native_perspective_c2b41a
    .a8
    eor #$FF
    clc
    adc a:$0FD8
    bmi project_wrapped_ui_target_with_native_perspective_c2b408
    bra project_wrapped_ui_target_with_native_perspective_c2b420
project_wrapped_ui_target_with_native_perspective_c2b41a:
    clc
    adc a:$0FD8
    bcs project_wrapped_ui_target_with_native_perspective_c2b408
project_wrapped_ui_target_with_native_perspective_c2b420:
    sec
    .a8
    sbc #$20
    bcc project_wrapped_ui_target_with_native_perspective_c2b408
    xba
    lda $09
    xba
    sta $09
    xba
    lsr
    lsr
    lsr
    lsr
    lsr
    .a8
    eor #$07
    clc
    rts
