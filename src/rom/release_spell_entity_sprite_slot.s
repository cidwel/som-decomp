; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-transfers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $41E1
release_spell_entity_sprite_slot:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    .a16
    lda #$8000
    sta a:$0000,X
    plb
    plp
    pld
    rts
