; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-topology.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_sprite_slot = $41E1

.segment "CODE"
.org $30E2
release_selected_spell_entity_sprite_pointers:
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
    phx
    dex
    dex
release_selected_spell_entity_sprite_pointers_c130f3:
    inx
    inx
    lsr $01
    bcc release_selected_spell_entity_sprite_pointers_c1310c
    ldy a:$0000,X
    beq release_selected_spell_entity_sprite_pointers_c130f3
    phx
    tyx
    jsr release_spell_entity_sprite_slot
    plx
    stz a:$0000,X
    stz a:$0001,X
    bra release_selected_spell_entity_sprite_pointers_c130f3
release_selected_spell_entity_sprite_pointers_c1310c:
    bne release_selected_spell_entity_sprite_pointers_c130f3
    plx
    pla
    plp
    pld
    rts
