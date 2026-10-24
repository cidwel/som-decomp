; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-inputs.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FF2A
read_native_multi5_auto_and_serial_controller_fields:
    php
    sep #$30
    stz $01
read_native_multi5_auto_and_serial_controller_fields_cfff2f:
    lda a:$4212
    .a8
    and #$01
    bne read_native_multi5_auto_and_serial_controller_fields_cfff2f
    lda a:$4219
    sta $0B
    lda a:$4218
    sta $0A
    .a8
    and #$0F
    sta $10
    lda a:$4016
    lsr
    rol $10
    lda a:$421B
    sta $09
    lda a:$421A
    sta $08
    .a8
    and #$0F
    sta $0F
    lda a:$421F
    sta $07
    lda a:$421E
    sta $06
    .a8
    and #$0F
    sta $0E
    lda a:$4017
    lsr
    rol $0F
    lsr
    rol $0E
    stz a:$4201
    .i8
    ldy #$10
read_native_multi5_auto_and_serial_controller_fields_cfff74:
    lda a:$4017
    rep #$20
    lsr
    rol $04
    lsr
    rol $02
    sep #$20
    dey
    bne read_native_multi5_auto_and_serial_controller_fields_cfff74
    lda $04
    .a8
    and #$0F
    sta $0D
    lda $02
    .a8
    and #$0F
    sta $0C
    lda a:$4017
    lsr
    rol $0D
    lsr
    rol $0C
    .a8
    lda #$80
    sta a:$4201
    plp
    rts
