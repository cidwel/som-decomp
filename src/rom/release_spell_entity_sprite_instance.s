; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-activation.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_individual_sprite_instance = $40BE

.segment "CODE"
.org $40E5
release_spell_entity_sprite_instance:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    lda a:$8420
    beq release_spell_entity_sprite_instance_c140fd
    jsr release_spell_entity_individual_sprite_instance
    bra release_spell_entity_sprite_instance_c14113
release_spell_entity_sprite_instance_c140fd:
    stz a:$0008,X
    txy
    .a8
    lda #$04
    sta $01
release_spell_entity_sprite_instance_c14105:
    phy
    ldx a:$0000,Y
    jsr release_spell_entity_individual_sprite_instance
    ply
    iny
    iny
    dec $01
    bne release_spell_entity_sprite_instance_c14105
release_spell_entity_sprite_instance_c14113:
    plb
    pla
    plp
    pld
    rts
