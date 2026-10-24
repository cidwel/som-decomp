; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-events.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2EEC
install_spell_entity_irq_handler:
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
    lda #$00C0
    sta f:$004209
    lda f:$000100
    sta a:$822C
    lda f:$000102
    sta a:$822E
    sep #$20
    .a8
    lda #$5C
    sta f:$000100
    .a8
    lda #$5E
    sta f:$000101
    .a8
    lda #$2F
    sta f:$000102
    .a8
    lda #$C1
    sta f:$000103
    inc a:$822A
    lda f:$004210
    plb
    plp
    pld
    rts
