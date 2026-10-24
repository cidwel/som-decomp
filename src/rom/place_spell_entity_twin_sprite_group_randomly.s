; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_bounded_random_long = $C12ED1

.segment "CODE"
.org $2DB0
place_spell_entity_twin_sprite_group_randomly:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stx $01
    sty $03
    .a16
    lda #$0040
    jsl f:draw_spell_entity_bounded_random_long
    sec
    .a16
    sbc #$0020
    ldy $03
    clc
    adc a:$0002,Y
    ldx $01
    sta a:$0016,X
    .a16
    lda #$0040
    jsl f:draw_spell_entity_bounded_random_long
    sec
    .a16
    sbc #$0020
    ldy $03
    clc
    adc a:$0000,Y
    ldx $01
    sta a:$0014,X
    sep #$20
    .a8
    lda #$04
    jsl f:draw_spell_entity_bounded_random_long
    .a8
    eor #$FF
    inc
    ldx $01
    sta a:$0018,X
    pla
    pla
    pla
    pla
    plp
    pld
    rts
