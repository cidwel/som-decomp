; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-direction.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_bounded_random_long = $C12ED1

.segment "CODE"
.org $FA6F
adjust_spell_entity_trail_velocity:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda $05,S
    stz $03
    stz $05
    phx
    .a16
    lda #$0004
    jsl f:draw_spell_entity_bounded_random_long
    inc
    inc
    plx
    sta a:$014E,X
    asl
    asl
    asl
    asl
    sta $01
    lda a:$014C,X
    .a16
    and #$0003
    beq adjust_spell_entity_trail_velocity_d3fb09
    dec
    beq adjust_spell_entity_trail_velocity_d3fac5
    dec
    beq adjust_spell_entity_trail_velocity_d3fae7
    .a16
    lda #$FFF0
    sta $05
    clc
    adc a:$0144,X
    sec
    sbc a:$0140,X
    bcs adjust_spell_entity_trail_velocity_d3fad8
    .a16
    eor #$FFFF
    inc
adjust_spell_entity_trail_velocity_d3fab6:
    .a16
    cmp #$0020
    bcs adjust_spell_entity_trail_velocity_d3fb29
    .a16
    cmp #$0010
    bcc adjust_spell_entity_trail_velocity_d3fb29
    inc a:$014E,X
    bra adjust_spell_entity_trail_velocity_d3fb29
adjust_spell_entity_trail_velocity_d3fac5:
    .a16
    lda #$0010
    sta $05
    clc
    adc a:$0144,X
    sec
    sbc a:$0140,X
    bcs adjust_spell_entity_trail_velocity_d3fab6
    .a16
    eor #$FFFF
    inc
adjust_spell_entity_trail_velocity_d3fad8:
    .a16
    cmp #$0020
    bcs adjust_spell_entity_trail_velocity_d3fb29
    .a16
    cmp #$0010
    bcc adjust_spell_entity_trail_velocity_d3fb29
    dec a:$014E,X
    bra adjust_spell_entity_trail_velocity_d3fb29
adjust_spell_entity_trail_velocity_d3fae7:
    .a16
    lda #$FFF0
    sta $03
    clc
    adc a:$0146,X
    sec
    sbc a:$0142,X
    bcs adjust_spell_entity_trail_velocity_d3fb1c
    .a16
    eor #$FFFF
    inc
adjust_spell_entity_trail_velocity_d3fafa:
    .a16
    cmp #$0020
    bcs adjust_spell_entity_trail_velocity_d3fb29
    .a16
    cmp #$0010
    bcc adjust_spell_entity_trail_velocity_d3fb29
    inc a:$014E,X
    bra adjust_spell_entity_trail_velocity_d3fb29
adjust_spell_entity_trail_velocity_d3fb09:
    .a16
    lda #$0010
    sta $03
    clc
    adc a:$0146,X
    sec
    sbc a:$0142,X
    bcs adjust_spell_entity_trail_velocity_d3fafa
    .a16
    eor #$FFFF
    inc
adjust_spell_entity_trail_velocity_d3fb1c:
    .a16
    cmp #$0020
    bcs adjust_spell_entity_trail_velocity_d3fb29
    .a16
    cmp #$0010
    bcc adjust_spell_entity_trail_velocity_d3fb29
    dec a:$014E,X
adjust_spell_entity_trail_velocity_d3fb29:
    lda $03
    sta a:$014A,X
    lda $05
    sta a:$0148,X
    sta $05,S
    tsc
    clc
    .a16
    adc #$0004
    tcs
    pla
    plp
    pld
    rts
