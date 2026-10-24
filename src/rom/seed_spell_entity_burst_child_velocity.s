; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_bounded_random_long = $C12ED1
scale_spell_entity_signed_angle_vector_long = $C12EC9
scale_spell_entity_signed_quarter_turn_vector_long = $C12ECD

.segment "CODE"
.org $EA93
seed_spell_entity_burst_child_velocity:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    lda a:$0054,X
    bne seed_spell_entity_burst_child_velocity_d3eaac
    .a16
    lda #$8000
    sta a:$000E,Y
    jmp seed_spell_entity_burst_child_velocity_d3eb7a
seed_spell_entity_burst_child_velocity_d3eaac:
    dec
    sta a:$0054,X
    sty $01
    stx $08
    lda a:$0052,X
    sta $03
    lda a:$0050,X
    sta $05
    .a16
    lda #$0000
    sta a:$000E,Y
    sep #$20
    jsl f:draw_spell_entity_bounded_random_long
    .a8
    and #$F0
    sta $07
    .i16
    ldx #$0060
    lda $07
    jsl f:scale_spell_entity_signed_angle_vector_long
    rep #$20
    txa
    clc
    adc $05
    ldy $01
    sta a:$0003,Y
    .i16
    ldx #$0060
    lda $07
    jsl f:scale_spell_entity_signed_quarter_turn_vector_long
    txa
    clc
    adc $03
    ldy $01
    sta a:$0006,Y
    ldx $08
    lda a:$0050,X
    stz $0A
    sec
    sbc a:$0003,Y
    bmi seed_spell_entity_burst_child_velocity_d3eb05
    bvc seed_spell_entity_burst_child_velocity_d3eb0d
    bra seed_spell_entity_burst_child_velocity_d3eb07
seed_spell_entity_burst_child_velocity_d3eb05:
    bvs seed_spell_entity_burst_child_velocity_d3eb0d
seed_spell_entity_burst_child_velocity_d3eb07:
    dec $0A
    .a16
    eor #$FFFF
    inc
seed_spell_entity_burst_child_velocity_d3eb0d:
    xba
    sta f:$004204
    sep #$20
    .a8
    lda #$D2
    sta f:$004206
    rep #$20
    pha
    pla
    pha
    pla
    lda f:$004214
    lsr $0A
    bcc seed_spell_entity_burst_child_velocity_d3eb2c
    .a16
    eor #$FFFF
    inc
seed_spell_entity_burst_child_velocity_d3eb2c:
    sta a:$0008,Y
    sep #$20
    lda $0A
    sta a:$000A,Y
    rep #$20
    lda a:$0052,X
    stz $0A
    sec
    sbc a:$0006,Y
    bmi seed_spell_entity_burst_child_velocity_d3eb47
    bvc seed_spell_entity_burst_child_velocity_d3eb4f
    bra seed_spell_entity_burst_child_velocity_d3eb49
seed_spell_entity_burst_child_velocity_d3eb47:
    bvs seed_spell_entity_burst_child_velocity_d3eb4f
seed_spell_entity_burst_child_velocity_d3eb49:
    dec $0A
    .a16
    eor #$FFFF
    inc
seed_spell_entity_burst_child_velocity_d3eb4f:
    xba
    sta f:$004204
    sep #$20
    .a8
    lda #$D2
    sta f:$004206
    rep #$20
    pha
    pla
    pha
    pla
    lda f:$004214
    lsr $0A
    bcc seed_spell_entity_burst_child_velocity_d3eb6e
    .a16
    eor #$FFFF
    inc
seed_spell_entity_burst_child_velocity_d3eb6e:
    sta a:$000B,Y
    sep #$20
    lda $0A
    sta a:$000D,Y
    rep #$20
seed_spell_entity_burst_child_velocity_d3eb7a:
    tsc
    clc
    .a16
    adc #$000B
    tcs
    plp
    pld
    rts
