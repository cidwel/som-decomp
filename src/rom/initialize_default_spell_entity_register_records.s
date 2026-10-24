; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514

.segment "CODE"
.org $445D
initialize_default_spell_entity_register_records:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$FCC2
    stx $02
    .a8
    lda #$DC
    sta $04
    .a8
    lda #$26
    sta $01
initialize_default_spell_entity_register_records_c1447c:
    lda [$02]
    jsr allocate_spell_entity_register_record
    .i16
    ldy #$0001
    lda [$02],Y
    sta a:$0002,X
    stz a:$0003,X
    jsr append_spell_entity_transient_register_record
    ldx $02
    inx
    inx
    stx $02
    dec $01
    bne initialize_default_spell_entity_register_records_c1447c
    plb
    pla
    pla
    pla
    pla
    plp
    pld
    rts
