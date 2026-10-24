; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-direction.md.
.setcpu "65816"
.smart
.a8
.i16

finish_spell_entity_trail_target_arrival = $FBB6
launch_spell_entity_trail_child = $FB3F

.segment "CODE"
.org $FC44
advance_spell_entity_trail_target_motion:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    tyx
    stz $01
    lda a:$0146,X
    clc
    adc a:$014A,X
    sta a:$0146,X
    sec
    sbc a:$0142,X
    bcs advance_spell_entity_trail_target_motion_d3fc62
    .a16
    eor #$FFFF
    inc
advance_spell_entity_trail_target_motion_d3fc62:
    .a16
    cmp #$0010
    bcs advance_spell_entity_trail_target_motion_d3fc69
    inc $01
advance_spell_entity_trail_target_motion_d3fc69:
    lda a:$0144,X
    clc
    adc a:$0148,X
    sta a:$0144,X
    sec
    sbc a:$0140,X
    bcs advance_spell_entity_trail_target_motion_d3fc7d
    .a16
    eor #$FFFF
    inc
advance_spell_entity_trail_target_motion_d3fc7d:
    .a16
    cmp #$0010
    bcs advance_spell_entity_trail_target_motion_d3fc8b
    ldy $01
    beq advance_spell_entity_trail_target_motion_d3fc8b
    jsr finish_spell_entity_trail_target_arrival
    bra advance_spell_entity_trail_target_motion_d3fc8e
advance_spell_entity_trail_target_motion_d3fc8b:
    jsr launch_spell_entity_trail_child
advance_spell_entity_trail_target_motion_d3fc8e:
    lda a:$0146,X
    sta a:$0004,Y
    lda a:$0144,X
    sta a:$0002,Y
    .a16
    lda #$0001
    sta a:$0008,Y
    sep #$20
    pla
    pla
    plp
    pld
    rts
