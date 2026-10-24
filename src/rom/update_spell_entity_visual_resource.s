; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_spell_entity_extra_sprite_words = $36D4

.segment "CODE"
.org $3711
update_spell_entity_visual_resource:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    stx $01
    dec a:$0012,X
    bne update_spell_entity_visual_resource_c1373c
    lda a:$0014,X
    sta a:$0012,X
    txy
    lda a:$0010,Y
    .a16
    and #$000F
    asl
    tax
    jsr ($36BC,X)
    ldx $01
update_spell_entity_visual_resource_c1373c:
    dec a:$001E,X
    bne update_spell_entity_visual_resource_c13757
    lda a:$0020,X
    sta a:$001E,X
    txy
    lda a:$0010,Y
    .a16
    and #$00F0
    lsr
    lsr
    lsr
    tax
    jsr ($36C4,X)
    ldx $01
update_spell_entity_visual_resource_c13757:
    dec a:$0026,X
    bne update_spell_entity_visual_resource_c1375f
    jsr rotate_spell_entity_extra_sprite_words
update_spell_entity_visual_resource_c1375f:
    .a16
    lda #$0000
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
