; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $44F7
release_spell_entity_register_record:
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
    txa
    beq release_spell_entity_register_record_c14510
    lda a:$8428
    sta a:$0000,X
    stx a:$8428
release_spell_entity_register_record_c14510:
    plb
    plp
    pld
    rts
