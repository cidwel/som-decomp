; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-objects.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12e7c = $C12E7C
routine_c12e88 = $C12E88

.segment "CODE"
.org $F983
release_spell_entity_trail_sprite_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stx $03
    txy
    .a16
    lda #$0014
    sta $01
release_spell_entity_trail_sprite_object_d3f996:
    ldx a:$0000,Y
    phy
    jsl f:routine_c12e88
    ply
    clc
    tya
    .a16
    adc #$0010
    tay
    dec $01
    bne release_spell_entity_trail_sprite_object_d3f996
    ldx $03
    jsl f:routine_c12e7c
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
