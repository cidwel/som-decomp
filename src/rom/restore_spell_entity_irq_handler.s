; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-events.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2F33
restore_spell_entity_irq_handler:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    lda a:$822A
    beq restore_spell_entity_irq_handler_c12f48
    dec a:$822A
    bne restore_spell_entity_irq_handler_c12f5a
restore_spell_entity_irq_handler_c12f48:
    rep #$20
    lda a:$822C
    sta f:$000100
    lda a:$822E
    sta f:$000102
    sep #$20
restore_spell_entity_irq_handler_c12f5a:
    plb
    plp
    pld
    rts
