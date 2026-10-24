; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-instances.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3FD0
find_free_spell_entity_sprite_quad:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    ldx a:$841C
    beq find_free_spell_entity_sprite_quad_c1402b
    sta $01
    clc
    rep #$20
    txa
    .a16
    adc #$0100
    tax
    sep #$20
    .i16
    ldy #$0010
find_free_spell_entity_sprite_quad_c13ff0:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    bne find_free_spell_entity_sprite_quad_c14006
    lda a:$000B,X
    cmp $01
    beq find_free_spell_entity_sprite_quad_c1402b
find_free_spell_entity_sprite_quad_c14006:
    dey
    bne find_free_spell_entity_sprite_quad_c13ff0
    clc
    rep #$20
    txa
    .a16
    adc #$0100
    tax
    sep #$20
    .i16
    ldy #$0010
find_free_spell_entity_sprite_quad_c14016:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    beq find_free_spell_entity_sprite_quad_c1402b
    dey
    bne find_free_spell_entity_sprite_quad_c14016
    .i16
    ldx #$0000
find_free_spell_entity_sprite_quad_c1402b:
    pla
    plp
    pld
    rts
