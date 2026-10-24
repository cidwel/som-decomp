; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-events.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $397D
classify_spell_entity_facing:
    phd
    php
    rep #$20
    sep #$20
    lda a:$0010,Y
    beq classify_spell_entity_facing_c13994
    .a8
    cmp #$01
    beq classify_spell_entity_facing_c13998
    .a8
    cmp #$02
    beq classify_spell_entity_facing_c1399c
    .a8
    lda #$80
    bra classify_spell_entity_facing_c1399e
classify_spell_entity_facing_c13994:
    .a8
    lda #$C0
    bra classify_spell_entity_facing_c1399e
classify_spell_entity_facing_c13998:
    .a8
    lda #$40
    bra classify_spell_entity_facing_c1399e
classify_spell_entity_facing_c1399c:
    .a8
    lda #$00
classify_spell_entity_facing_c1399e:
    plp
    pld
    rts
