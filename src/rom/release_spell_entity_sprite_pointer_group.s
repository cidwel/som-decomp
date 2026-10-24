; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-groups.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12e88 = $C12E88

.segment "CODE"
.org $395B
release_spell_entity_sprite_pointer_group:
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
    sta $01
    txy
release_spell_entity_sprite_pointer_group_c1396a:
    phy
    ldx a:$0000,Y
    jsl f:routine_c12e88
    ply
    iny
    iny
    dec $01
    bne release_spell_entity_sprite_pointer_group_c1396a
    pla
    plp
    pld
    rts
