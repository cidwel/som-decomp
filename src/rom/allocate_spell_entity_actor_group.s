; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-slots.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $286C
allocate_spell_entity_actor_group:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx a:$8216
    .i16
    ldy #$0020
allocate_spell_entity_actor_group_c1287d:
    lda a:$0000,X
    beq allocate_spell_entity_actor_group_c12885
    dey
    bne allocate_spell_entity_actor_group_c1287d
allocate_spell_entity_actor_group_c12885:
    tya
    beq allocate_spell_entity_actor_group_c1288b
    inc a:$0000,X
allocate_spell_entity_actor_group_c1288b:
    sec
    .a8
    sbc #$20
    .a8
    eor #$FF
    inc
    inc
    plb
    plp
    pld
    rts
