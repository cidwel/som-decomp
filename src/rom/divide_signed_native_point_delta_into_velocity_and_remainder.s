; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-producer.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A631
divide_signed_native_point_delta_into_velocity_and_remainder:
    sep #$20
    sec
    sbc $00
    sta $00
    bpl divide_signed_native_point_delta_into_velocity_and_remainder_c2a63d
    .a8
    eor #$FF
    inc
divide_signed_native_point_delta_into_velocity_and_remainder_c2a63d:
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
    lda $08
    sta f:$004206
    xba
    sec
    sbc $01
    sta $01
    bpl divide_signed_native_point_delta_into_velocity_and_remainder_c2a658
    .a8
    eor #$FF
    inc
divide_signed_native_point_delta_into_velocity_and_remainder_c2a658:
    pha
    nop
    nop
    lda f:$004214
    sta $04
    lda f:$004216
    sta $02
    pla
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
    lda $08
    sta f:$004206
    lda $04
    bit $00
    bpl divide_signed_native_point_delta_into_velocity_and_remainder_c2a681
    .a8
    eor #$FF
    inc
divide_signed_native_point_delta_into_velocity_and_remainder_c2a681:
    xba
    nop
    nop
    nop
    nop
    lda f:$004216
    sta $03
    lda f:$004214
    bit $01
    bpl divide_signed_native_point_delta_into_velocity_and_remainder_c2a697
    .a8
    eor #$FF
    inc
divide_signed_native_point_delta_into_velocity_and_remainder_c2a697:
    xba
    rts
