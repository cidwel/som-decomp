; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $44B3
allocate_spell_entity_register_record:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    ldx a:$8428
    beq allocate_spell_entity_register_record_c144f3
    .a16
    and #$00FF
    pha
    lda a:$0000,X
    sta a:$8428
    pla
    sta a:$0000,X
    txy
    tax
    lda f:$DCFC8E,X
    .a16
    and #$00FF
    beq allocate_spell_entity_register_record_c144e6
    .a16
    cmp #$0001
    beq allocate_spell_entity_register_record_c144e6
    tax
allocate_spell_entity_register_record_c144e6:
    txa
    clc
    adc a:$8432
    tax
    lda a:$0000,X
    sta a:$0002,Y
    tyx
allocate_spell_entity_register_record_c144f3:
    plb
    plp
    pld
    rts
