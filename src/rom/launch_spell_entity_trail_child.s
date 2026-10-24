; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-direction.md.
.setcpu "65816"
.smart
.a8
.i16

adjust_spell_entity_trail_velocity = $FA6F
select_spell_entity_trail_turn_direction = $FA1D

.segment "CODE"
.org $FB3F
launch_spell_entity_trail_child:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    stx $01
    lda a:$014C,X
    .a16
    and #$0003
    sta $03
    lda a:$0150,X
    inc
    .a16
    cmp #$0014
    bcc launch_spell_entity_trail_child_d3fb60
    .a16
    lda #$0000
launch_spell_entity_trail_child_d3fb60:
    sta a:$0150,X
    asl
    asl
    asl
    asl
    clc
    adc $01
    sta $05
    dec a:$014E,X
    bne launch_spell_entity_trail_child_d3fb83
    jsr select_spell_entity_trail_turn_direction
    lda a:$014C,X
    ldy $05
    sta a:$000A,Y
    sta $03
    jsr adjust_spell_entity_trail_velocity
    bra launch_spell_entity_trail_child_d3fb90
launch_spell_entity_trail_child_d3fb83:
    lda $03
    asl
    asl
    ora $03
    sta $03
    ldy $05
    sta a:$000A,Y
launch_spell_entity_trail_child_d3fb90:
    lda $03
    asl
    clc
    adc $03
    asl
    asl
    clc
    .a16
    adc #$FD5A
    sec
    .a16
    sbc #$F800
    ldy $05
    sta a:$0006,Y
    .a16
    lda #$0006
    sta a:$000C,Y
    ldx $01
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
