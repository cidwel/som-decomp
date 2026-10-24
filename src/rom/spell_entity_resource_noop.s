; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $36B3
spell_entity_resource_noop:
    phd
    php
    rep #$20
    sep #$20
    plp
    pld
    rts
