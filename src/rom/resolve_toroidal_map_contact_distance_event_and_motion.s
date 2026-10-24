; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

compare_native_contact_hitboxes_and_publish_collision_flags = $D14A
test_and_record_contact_event_edge_bit = $D12C
test_hero_facing_and_contact_event_edge = $D107

.segment "CODE"
.org $CE62
resolve_toroidal_map_contact_distance_event_and_motion:
    sep #$20
    lda a:$E089,Y
    .a8
    and #$03
    asl
    asl
    clc
    .a8
    adc #$0A
    sta $04
    stz $05
    rep #$20
    stz $06
    lda a:$E002,X
    sec
    sbc a:$E002,Y
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1ce85
    .a16
    eor #$FFFF
    inc
    inc $06
resolve_toroidal_map_contact_distance_event_and_motion_c1ce85:
    cmp $18
    bcc resolve_toroidal_map_contact_distance_event_and_motion_c1ce91
    .a16
    eor #$FFFF
    sec
    adc $C0
    inc $06
resolve_toroidal_map_contact_distance_event_and_motion_c1ce91:
    sta $0A
    cmp $04
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1ce9c
    .a16
    lda #$0000
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1cea6
resolve_toroidal_map_contact_distance_event_and_motion_c1ce9c:
    sbc $04
    .a16
    cmp #$0080
    bcc resolve_toroidal_map_contact_distance_event_and_motion_c1cea6
    .a16
    lda #$0080
resolve_toroidal_map_contact_distance_event_and_motion_c1cea6:
    sta $08
    lda a:$E004,X
    sec
    sbc a:$E004,Y
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1ceb7
    .a16
    eor #$FFFF
    inc
    inc $07
resolve_toroidal_map_contact_distance_event_and_motion_c1ceb7:
    cmp $1A
    bcc resolve_toroidal_map_contact_distance_event_and_motion_c1cec3
    .a16
    eor #$FFFF
    sec
    adc $C2
    inc $07
resolve_toroidal_map_contact_distance_event_and_motion_c1cec3:
    sta $0B
    .a16
    cmp #$0008
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cecf
    .a16
    lda #$0000
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1ceda
resolve_toroidal_map_contact_distance_event_and_motion_c1cecf:
    .a16
    sbc #$0008
    .a16
    cmp #$0080
    bcc resolve_toroidal_map_contact_distance_event_and_motion_c1ceda
    .a16
    lda #$0080
resolve_toroidal_map_contact_distance_event_and_motion_c1ceda:
    sep #$20
    sta $09
    lsr $07
    ror $07
    lda $06
    lsr
    ror
    sta $06
    lsr
    ora $07
    .a8
    and #$C0
    .i16
    cpx #$0000
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cefe
    sta a:$E052,Y
    rep #$20
    lda $08
    sta a:$E050,Y
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1cf19
resolve_toroidal_map_contact_distance_event_and_motion_c1cefe:
    .i16
    cpx #$0200
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cf0f
    sta a:$E055,Y
    rep #$20
    lda $08
    sta a:$E053,Y
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1cf19
resolve_toroidal_map_contact_distance_event_and_motion_c1cf0f:
    sta a:$E058,Y
    rep #$20
    lda $08
    sta a:$E056,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1cf19:
    sep #$20
    lda $08
    ora $09
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1cf38
resolve_toroidal_map_contact_distance_event_and_motion_c1cf21:
    phx
    pla
    pla
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cf28
    .a8
    lda #$01
resolve_toroidal_map_contact_distance_event_and_motion_c1cf28:
    sta $00
    asl
    asl
    asl
    ora $00
    .a8
    eor #$FF
    and a:$E04E,Y
    sta a:$E04E,Y
    rts
resolve_toroidal_map_contact_distance_event_and_motion_c1cf38:
    bit $ED
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1cf3f
    jsr compare_native_contact_hitboxes_and_publish_collision_flags
resolve_toroidal_map_contact_distance_event_and_motion_c1cf3f:
    sep #$20
    lda $08
    .a8
    cmp #$18
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cf21
    lda $09
    .a8
    cmp #$18
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cf21
    lda a:$E03F,Y
    sta $02
    .a8
    and #$70
    .a8
    cmp #$10
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cf65
    lda a:$E02C,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1cf65
    clc
    jsr test_and_record_contact_event_edge_bit
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cf65
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1cfd2
resolve_toroidal_map_contact_distance_event_and_motion_c1cf65:
    lda $08
    .a8
    cmp #$08
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cf71
    lda $09
    .a8
    cmp #$08
    bcc resolve_toroidal_map_contact_distance_event_and_motion_c1cf84
resolve_toroidal_map_contact_distance_event_and_motion_c1cf71:
    phx
    pla
    pla
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cf78
    .a8
    lda #$01
resolve_toroidal_map_contact_distance_event_and_motion_c1cf78:
    asl
    asl
    asl
    .a8
    eor #$FF
    and a:$E04E,Y
    sta a:$E04E,Y
    rts
resolve_toroidal_map_contact_distance_event_and_motion_c1cf84:
    lda a:$E010,X
    .a8
    cmp #$02
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cf93
    lda $08
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    lda $09
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1cf99
resolve_toroidal_map_contact_distance_event_and_motion_c1cf93:
    lda $09
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    lda $08
resolve_toroidal_map_contact_distance_event_and_motion_c1cf99:
    .a8
    cmp #$03
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    lda $02
    .a8
    and #$70
    .a8
    cmp #$20
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1cfc7
    .a8
    cmp #$30
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cfe5
    lda a:$E010,X
    .a8
    cmp #$02
    bcc resolve_toroidal_map_contact_distance_event_and_motion_c1cfb4
    .a8
    eor #$80
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1cfb6
resolve_toroidal_map_contact_distance_event_and_motion_c1cfb4:
    .a8
    eor #$01
resolve_toroidal_map_contact_distance_event_and_motion_c1cfb6:
    cmp a:$E010,Y
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1d017
    lda a:$E02C,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1cfe5
    jsr test_hero_facing_and_contact_event_edge
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cfe5
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1cfd2
resolve_toroidal_map_contact_distance_event_and_motion_c1cfc7:
    lda a:$E02C,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1cfe5
    sec
    jsr test_and_record_contact_event_edge_bit
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1cfe5
resolve_toroidal_map_contact_distance_event_and_motion_c1cfd2:
    rep #$20
    lda $0E
    bne resolve_toroidal_map_contact_distance_event_and_motion_c1d017
    lda a:$E03E,Y
    .a16
    and #$0FFF
    sta $0E
    sty $1E
    stx $1C
resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4:
    rts
resolve_toroidal_map_contact_distance_event_and_motion_c1cfe5:
    sep #$20
    lda a:$E074,Y
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    lda a:$E045,X
    .a8
    cmp #$18
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    lda a:$E045,Y
    .a8
    cmp #$18
    bcs resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    bit $02
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d00b
    cpy $3A
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d007
    lda a:$E060,Y
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d00b
resolve_toroidal_map_contact_distance_event_and_motion_c1d007:
    .a8
    lda #$80
    trb $02
resolve_toroidal_map_contact_distance_event_and_motion_c1d00b:
    lda $08
    ora $09
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d017
    lda $02
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1cfe4
    bmi resolve_toroidal_map_contact_distance_event_and_motion_c1d090
resolve_toroidal_map_contact_distance_event_and_motion_c1d017:
    lda a:$E006,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d042
    eor $06
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d042
    lda $02
    .a8
    and #$80
    .a8
    ora #$01
    ora a:$E029,X
    sta a:$E029,X
    bit $02
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d042
    lda a:$E006,X
    .a8
    and #$80
    .a8
    ora #$01
    sta a:$E03A,Y
    .a8
    lda #$04
    ora a:$E029,Y
    sta a:$E029,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1d042:
    lda a:$E007,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d06d
    eor $07
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d06d
    lda $02
    .a8
    and #$80
    .a8
    ora #$02
    ora a:$E029,X
    sta a:$E029,X
    bit $02
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d06d
    lda a:$E007,X
    .a8
    and #$80
    .a8
    ora #$01
    sta a:$E03B,Y
    .a8
    lda #$08
    ora a:$E029,Y
    sta a:$E029,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1d06d:
    lda a:$E006,Y
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d07e
    eor $06
    bmi resolve_toroidal_map_contact_distance_event_and_motion_c1d07e
    .a8
    lda #$01
    ora a:$E029,Y
    sta a:$E029,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1d07e:
    lda a:$E007,Y
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d08f
    eor $07
    bmi resolve_toroidal_map_contact_distance_event_and_motion_c1d08f
    .a8
    lda #$02
    ora a:$E029,Y
    sta a:$E029,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1d08f:
    rts
resolve_toroidal_map_contact_distance_event_and_motion_c1d090:
    lda a:$E006,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d0b7
    eor $06
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d0b7
    eor $06
    .a8
    and #$80
    .a8
    ora #$01
    sta a:$E03A,Y
    sta a:$E03A,X
    .a8
    lda #$84
    ora a:$E029,X
    sta a:$E029,X
    .a8
    lda #$04
    ora a:$E029,Y
    sta a:$E029,Y
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1d0c8
resolve_toroidal_map_contact_distance_event_and_motion_c1d0b7:
    lda a:$E006,Y
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d0c8
    eor $06
    bmi resolve_toroidal_map_contact_distance_event_and_motion_c1d0c8
    .a8
    lda #$01
    ora a:$E029,Y
    sta a:$E029,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1d0c8:
    lda a:$E007,X
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d0ef
    eor $07
    bpl resolve_toroidal_map_contact_distance_event_and_motion_c1d0ef
    eor $07
    .a8
    and #$80
    .a8
    ora #$01
    sta a:$E03B,Y
    sta a:$E03B,X
    .a8
    lda #$88
    ora a:$E029,X
    sta a:$E029,X
    .a8
    lda #$08
    ora a:$E029,Y
    sta a:$E029,Y
    bra resolve_toroidal_map_contact_distance_event_and_motion_c1d100
resolve_toroidal_map_contact_distance_event_and_motion_c1d0ef:
    lda a:$E007,Y
    beq resolve_toroidal_map_contact_distance_event_and_motion_c1d100
    eor $07
    bmi resolve_toroidal_map_contact_distance_event_and_motion_c1d100
    .a8
    lda #$02
    ora a:$E029,Y
    sta a:$E029,Y
resolve_toroidal_map_contact_distance_event_and_motion_c1d100:
    rep #$20
    txa
    sta a:$E05B,Y
    rts
