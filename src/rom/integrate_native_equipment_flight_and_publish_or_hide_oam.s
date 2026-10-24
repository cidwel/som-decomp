; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-flight.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DDBD
integrate_native_equipment_flight_and_publish_or_hide_oam:
    lda $0C,X
    tay
    sep #$20
    lda $03,X
    sec
    .a8
    sbc #$03
    sta $03,X
    lsr
    lsr
    lsr
    .a8
    bit #$10
    beq integrate_native_equipment_flight_and_publish_or_hide_oam_d0ddd2
    .a8
    ora #$E0
integrate_native_equipment_flight_and_publish_or_hide_oam_d0ddd2:
    clc
    adc $02,X
    sta $02,X
    .a8
    cmp #$E8
    bcs integrate_native_equipment_flight_and_publish_or_hide_oam_d0de1e
    .a8
    eor #$FF
    inc
    pha
    rep #$20
    lda $0A,X
    clc
    adc $08,X
    sep #$20
    sta $0A,X
    xba
    clc
    adc $01,X
    sta $01,X
    clc
    adc $01,S
    sta $01,S
    pla
    .a8
    cmp #$F0
    bcc integrate_native_equipment_flight_and_publish_or_hide_oam_d0ddfc
    .a8
    lda #$E8
integrate_native_equipment_flight_and_publish_or_hide_oam_d0ddfc:
    xba
    rep #$20
    .a16
    and #$FF00
    pha
    lda $06,X
    clc
    adc $04,X
    sep #$20
    sta $06,X
    xba
    clc
    adc $00,X
    sta $00,X
    rep #$20
    .a16
    and #$00FF
    ora $01,S
    sta a:$0000,Y
    pla
    rts
integrate_native_equipment_flight_and_publish_or_hide_oam_d0de1e:
    sep #$20
    inc a:$1826
    .a8
    lda #$E8
    sta a:$0001,Y
    rts
