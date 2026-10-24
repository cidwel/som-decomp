; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-direction.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FBB6
finish_spell_entity_trail_target_arrival:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    stx $01
    .i16
    ldy #$FE3A
    lda a:$014C,X
    .a16
    bit #$0001
    beq finish_spell_entity_trail_target_arrival_d3fbd7
    lda a:$0144,X
    sec
    sbc a:$0140,X
    bra finish_spell_entity_trail_target_arrival_d3fbde
finish_spell_entity_trail_target_arrival_d3fbd7:
    lda a:$0146,X
    sec
    sbc a:$0142,X
finish_spell_entity_trail_target_arrival_d3fbde:
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    xba
    eor a:$014C,X
    .a16
    and #$0002
    bne finish_spell_entity_trail_target_arrival_d3fbf0
    .i16
    ldy #$FE1A
finish_spell_entity_trail_target_arrival_d3fbf0:
    sty $07
    lda a:$014C,X
    .a16
    and #$0003
    asl
    asl
    asl
    clc
    adc $07
    sta $07
    lda a:$0150,X
    inc
    .a16
    cmp #$0014
    bcc finish_spell_entity_trail_target_arrival_d3fc0c
    .a16
    lda #$0000
finish_spell_entity_trail_target_arrival_d3fc0c:
    sta a:$0150,X
    asl
    asl
    asl
    asl
    clc
    adc $01
    tay
    lda a:$014C,X
    sta a:$000A,Y
    lda $07
    sec
    .a16
    sbc #$F800
    sta a:$0006,Y
    .a16
    lda #$0004
    sta a:$000C,Y
    stz a:$014A,X
    stz a:$0148,X
    .a16
    lda #$0078
    sta a:$0152,X
    inc a:$0154,X
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
