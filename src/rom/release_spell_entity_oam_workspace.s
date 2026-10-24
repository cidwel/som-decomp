; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-oam.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_with_saved_bank = $3D7D

.segment "CODE"
.org $3E7B
release_spell_entity_oam_workspace:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx a:$841A
    jsr release_spell_entity_heap_with_saved_bank
    ldx a:$841C
    jsr release_spell_entity_heap_with_saved_bank
    ldx a:$841E
    jsr release_spell_entity_heap_with_saved_bank
    plb
    plp
    pld
    rts
