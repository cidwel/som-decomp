; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-projection.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record = $386F

.segment "CODE"
.org $2E94
project_packed_spell_entity_sprite_record_long:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    lda $0A
    pha
    lda $08
    pha
    jsr project_packed_spell_entity_sprite_record
    pla
    pla
    sep #$20
    sta $01,S
    pla
    plp
    pld
    rtl
