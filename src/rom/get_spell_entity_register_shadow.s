; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $44A1
get_spell_entity_register_shadow:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    ldx a:$8432
    plb
    plp
    pld
    rts
