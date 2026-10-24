; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9AD4
transform_image_coefficients:
    rep #$20
    .i16
    ldx #$0000
transform_image_coefficients_9ad9:
    lda $00
    clc
    adc $10
    clc
    adc $20
    clc
    adc $30
    clc
    adc $40
    clc
    adc $50
    clc
    adc $60
    clc
    adc $70
    sta $80,X
    lda $00
    clc
    adc $10
    clc
    adc $20
    clc
    adc $30
    sec
    sbc $40
    sec
    sbc $50
    sec
    sbc $60
    sec
    sbc $70
    sta $82,X
    lda $00
    clc
    adc $10
    sec
    sbc $20
    sec
    sbc $30
    sec
    sbc $40
    sec
    sbc $50
    clc
    adc $60
    clc
    adc $70
    sta $84,X
    lda $00
    clc
    adc $10
    sec
    sbc $20
    sec
    sbc $30
    clc
    adc $40
    clc
    adc $50
    sec
    sbc $60
    sec
    sbc $70
    sta $86,X
    lda $00
    sec
    sbc $10
    sec
    sbc $20
    clc
    adc $30
    clc
    adc $40
    sec
    sbc $50
    sec
    sbc $60
    clc
    adc $70
    sta $88,X
    lda $00
    sec
    sbc $10
    sec
    sbc $20
    clc
    adc $30
    sec
    sbc $40
    clc
    adc $50
    clc
    adc $60
    sec
    sbc $70
    sta $8A,X
    lda $00
    sec
    sbc $10
    clc
    adc $20
    sec
    sbc $30
    sec
    sbc $40
    clc
    adc $50
    sec
    sbc $60
    clc
    adc $70
    sta $8C,X
    lda $00
    sec
    sbc $10
    clc
    adc $20
    sec
    sbc $30
    clc
    adc $40
    sec
    sbc $50
    clc
    adc $60
    sec
    sbc $70
    sta $8E,X
    txa
    clc
    .a16
    adc #$000E
    tax
    tdc
    inc
    inc
    tcd
    .a16
    and #$000F
    beq transform_image_coefficients_9bb3
    jmp transform_image_coefficients_9ad9
transform_image_coefficients_9bb3:
    tdc
    .a16
    and #$FF00
    tcd
    .i16
    ldx #$0000
transform_image_coefficients_9bbb:
    .a16
    lda #$0004
    clc
    adc $80
    clc
    adc $90
    clc
    adc $A0
    clc
    adc $B0
    clc
    adc $C0
    clc
    adc $D0
    clc
    adc $E0
    clc
    adc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9be1
    .a16
    ora #$F000
transform_image_coefficients_9be1:
    sta $00,X
    .a16
    lda #$0004
    clc
    adc $80
    clc
    adc $90
    clc
    adc $A0
    clc
    adc $B0
    sec
    sbc $C0
    sec
    sbc $D0
    sec
    sbc $E0
    sec
    sbc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9c09
    .a16
    ora #$F000
transform_image_coefficients_9c09:
    sta $02,X
    .a16
    lda #$0004
    clc
    adc $80
    clc
    adc $90
    sec
    sbc $A0
    sec
    sbc $B0
    sec
    sbc $C0
    sec
    sbc $D0
    clc
    adc $E0
    clc
    adc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9c31
    .a16
    ora #$F000
transform_image_coefficients_9c31:
    sta $04,X
    .a16
    lda #$0004
    clc
    adc $80
    clc
    adc $90
    sec
    sbc $A0
    sec
    sbc $B0
    clc
    adc $C0
    clc
    adc $D0
    sec
    sbc $E0
    sec
    sbc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9c59
    .a16
    ora #$F000
transform_image_coefficients_9c59:
    sta $06,X
    .a16
    lda #$0004
    clc
    adc $80
    sec
    sbc $90
    sec
    sbc $A0
    clc
    adc $B0
    clc
    adc $C0
    sec
    sbc $D0
    sec
    sbc $E0
    clc
    adc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9c81
    .a16
    ora #$F000
transform_image_coefficients_9c81:
    sta $08,X
    .a16
    lda #$0004
    clc
    adc $80
    sec
    sbc $90
    sec
    sbc $A0
    clc
    adc $B0
    sec
    sbc $C0
    clc
    adc $D0
    clc
    adc $E0
    sec
    sbc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9ca9
    .a16
    ora #$F000
transform_image_coefficients_9ca9:
    sta $0A,X
    .a16
    lda #$0004
    clc
    adc $80
    sec
    sbc $90
    clc
    adc $A0
    sec
    sbc $B0
    sec
    sbc $C0
    clc
    adc $D0
    sec
    sbc $E0
    clc
    adc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9cd1
    .a16
    ora #$F000
transform_image_coefficients_9cd1:
    sta $0C,X
    .a16
    lda #$0004
    clc
    adc $80
    sec
    sbc $90
    clc
    adc $A0
    sec
    sbc $B0
    clc
    adc $C0
    sec
    sbc $D0
    clc
    adc $E0
    sec
    sbc $F0
    lsr
    lsr
    lsr
    .a16
    bit #$1000
    beq transform_image_coefficients_9cf9
    .a16
    ora #$F000
transform_image_coefficients_9cf9:
    sta $0E,X
    txa
    clc
    .a16
    adc #$000E
    tax
    tdc
    inc
    inc
    tcd
    .a16
    and #$000F
    beq transform_image_coefficients_9d0d
    jmp transform_image_coefficients_9bbb
transform_image_coefficients_9d0d:
    rts
