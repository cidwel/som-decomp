; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-charge-input.md.
.setcpu "65816"
.smart
.a8
.i16

publish_charge_sound_only_for_controlled_hero = $BB27

.segment "CODE"
.org $B330
advance_selected_hero_charge_timing_and_publish_native_gauge:
    rep #$10
    .i16
    ldx #$0000
    txy
    lsr
    bcs advance_selected_hero_charge_timing_and_publish_native_gauge_c0b348
    .i16
    ldx #$0200
    .i16
    ldy #$0010
    lsr
    bcs advance_selected_hero_charge_timing_and_publish_native_gauge_c0b348
    .i16
    ldx #$0400
    .i16
    ldy #$0020
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b348:
    lda f:$7EE02C,X
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b35c
    .a8
    lda #$00
    sta f:$7EE085,X
    lda f:$7EE19C,X
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b380
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b381
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b35c:
    .i16
    cpx #$0000
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b369
    lda f:$7ECC7D
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b37c
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b381
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b369:
    .i16
    cpx #$0200
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b376
    lda f:$7ECC7E
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b37c
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b381
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b376:
    lda f:$7ECC7F
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b381
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b37c:
    sta f:$7EE085,X
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b380:
    rts
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b381:
    sta $01
    lda f:$7EE191,X
    .a8
    and #$02
    ora f:$7EE01C,X
    ora f:$7EE061,X
    ora f:$7EE1ED,X
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b380
    lda f:$7EE01F,X
    dec
    sta f:$7EE01F,X
    bmi advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3a5
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3a2:
    brl advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4cb
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3a5:
    stz $00
    .a8
    lda #$01
    sta f:$7EE01F,X
    lda $01
    xba
    .a8
    lda #$2C
    rep #$20
    cmp f:$7EE01A,X
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3a2
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3ba:
    lda f:$7EE01A,X
    xba
    sta $02
    sta $03
    xba
    sep #$20
    inc
    .a8
    cmp #$2D
    bcc advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3df
    .a8
    lda #$A8
    jsr publish_charge_sound_only_for_controlled_hero
    .a8
    lda #$00
    xba
    inc
    sta $02
    cmp $01
    xba
    bcc advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3df
    .a8
    lda #$2C
    inc $00
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3df:
    rep #$20
    sta f:$7EE01A,X
    sep #$20
    .a8
    and #$03
    .a8
    cmp #$01
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3f2
    .a8
    lda #$A7
    jsr publish_charge_sound_only_for_controlled_hero
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3f2:
    lda $04
    sta a:$4204
    stz a:$4205
    .a8
    lda #$09
    sta a:$4206
    .a8
    lda #$00
    xba
    sta f:$7EE19B,X
    lda $02
    clc
    .a8
    adc #$18
    sta a:$0A56,Y
    lda f:$7EE19C,X
    clc
    .a8
    adc #$28
    sta a:$0A57,Y
    tya
    clc
    adc a:$4214
    phy
    tay
    lda $03
    asl
    asl
    asl
    clc
    adc $03
    .a8
    adc #$38
    adc a:$4216
    sta a:$0A50,Y
    xba
    lda $29
    .a8
    bit #$04
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b44f
    .a8
    bit #$02
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b44f
    .i16
    cpx #$0000
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b44f
    .a8
    lda #$48
    .i16
    cpx #$0200
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b448
    .a8
    lda #$90
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b448:
    clc
    adc a:$0A50,Y
    sta a:$0A50,Y
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b44f:
    ply
    xba
    .a8
    cmp #$40
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b465
    lda $01
    xba
    .a8
    lda #$2C
    rep #$20
    cmp f:$7EE01A,X
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b465
    brl advance_selected_hero_charge_timing_and_publish_native_gauge_c0b3ba
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b465:
    sep #$20
    lda $00
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b483
    rep #$20
    lda f:$D27E28
    sta a:$0A58,Y
    sta a:$0A5A,Y
    lda f:$D27E2A
    sta a:$0A5C,Y
    sta a:$0A5E,Y
    bra advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4cb
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b483:
    lda $02
    asl
    asl
    lsr $02
    rep #$20
    .a16
    and #$003F
    tax
    bcc advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4ab
    lda f:$D27E04,X
    sta a:$0A58,Y
    lda f:$D27E06,X
    sta a:$0A5C,Y
    lda f:$D27E00,X
    sta a:$0A5A,Y
    sta a:$0A5E,Y
    bra advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4cb
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4ab:
    lda f:$D27E04,X
    sta a:$0A5A,Y
    lda f:$D27E06,X
    sta a:$0A5E,Y
    .a16
    lda #$0000
    .i16
    cpx #$0000
    beq advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4c5
    lda f:$D27E00,X
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4c5:
    sta a:$0A58,Y
    sta a:$0A5C,Y
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4cb:
    rep #$20
    tya
    lsr
    tax
    lda $F4
    lsr
    bcc advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4d9
    iny
    iny
    iny
    iny
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4d9:
    lda f:$001D04
    .a16
    and #$0020
    bne advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4ef
    lda a:$0A58,Y
    sta a:$060C,X
    lda a:$0A5A,Y
    sta a:$060E,X
    rts
advance_selected_hero_charge_timing_and_publish_native_gauge_c0b4ef:
    lda a:$0A58,Y
    sta f:$7EDE0C,X
    lda a:$0A5A,Y
    sta f:$7EDE0E,X
    rts
