; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16

divide_menu_number_using_snes_arithmetic_registers = $D0D7E2

.segment "CODE"
.org $DD44
derive_opposed_native_fixed_point_flight_steps:
    sep #$20
    php
    sta a:$1820
    .i16
    ldy #$FFFF
    sec
    sbc a:$1821
    bcs derive_opposed_native_fixed_point_flight_steps_d0dd5d
    lda a:$1821
    sec
    sbc a:$1820
    .i16
    ldy #$0001
derive_opposed_native_fixed_point_flight_steps_d0dd5d:
    rep #$20
    xba
    .a16
    and #$FF00
    phy
    tay
    php
    sep #$20
    .a8
    lda #$33
    jsl f:divide_menu_number_using_snes_arithmetic_registers
    rep #$20
    lda a:$4214
    plp
    ply
    .i16
    cpy #$FFFF
    bne derive_opposed_native_fixed_point_flight_steps_d0dd7e
    .a16
    eor #$FFFF
    inc
derive_opposed_native_fixed_point_flight_steps_d0dd7e:
    sta $04,X
    .a16
    eor #$FFFF
    inc
    sta $14,X
    .a16
    lda #$0000
    sta $06,X
    sta $16,X
    plp
    rts
