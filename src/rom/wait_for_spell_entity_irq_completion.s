; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-slots.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2FE4
wait_for_spell_entity_irq_completion:
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
    inc a:$8232
wait_for_spell_entity_irq_completion_c12ff4:
    lda f:$004211
    lda a:$8230
    beq wait_for_spell_entity_irq_completion_c12ff4
    dec a:$8230
    dec a:$8232
    plb
    plp
    pld
    rts
