; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-instances.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3F71
find_free_spell_entity_sprite_instance:
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
    ldx a:$841A
    beq find_free_spell_entity_sprite_instance_c13fcc
    sta $01
    clc
    rep #$20
    txa
    .a16
    adc #$0400
    tax
    sep #$20
    .i16
    ldy #$0040
find_free_spell_entity_sprite_instance_c13f91:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    bne find_free_spell_entity_sprite_instance_c13fa7
    lda a:$000B,X
    cmp $01
    beq find_free_spell_entity_sprite_instance_c13fcc
find_free_spell_entity_sprite_instance_c13fa7:
    dey
    bne find_free_spell_entity_sprite_instance_c13f91
    clc
    rep #$20
    txa
    .a16
    adc #$0400
    tax
    sep #$20
    .i16
    ldy #$0040
find_free_spell_entity_sprite_instance_c13fb7:
    sec
    rep #$20
    txa
    .a16
    sbc #$0010
    tax
    sep #$20
    lda a:$0008,X
    beq find_free_spell_entity_sprite_instance_c13fcc
    dey
    bne find_free_spell_entity_sprite_instance_c13fb7
    .i16
    ldx #$0000
find_free_spell_entity_sprite_instance_c13fcc:
    pla
    plp
    pld
    rts
