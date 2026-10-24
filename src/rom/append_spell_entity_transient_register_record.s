; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4514
append_spell_entity_transient_register_record:
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
    beq append_spell_entity_transient_register_record_c14538
    sec
    sbc a:$8426
    sep #$20
    ldy a:$8430
    sta a:$0001,Y
    stz a:$0001,X
    rep #$20
    stx a:$8430
append_spell_entity_transient_register_record_c14538:
    plb
    plp
    pld
    rts
