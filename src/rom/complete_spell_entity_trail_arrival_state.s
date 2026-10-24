; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FCF5
complete_spell_entity_trail_arrival_state:
    phd
    php
    rep #$20
    sep #$20
    tyx
    stz a:$0152,X
    inc a:$0154,X
    plp
    pld
    rts
