; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514

.segment "CODE"
.org $3597
cycle_spell_entity_blue_color:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    sty $01
    .a8
    lda #$32
    jsr allocate_spell_entity_register_record
    ldy $01
    lda a:$0022,Y
    inc
    .a8
    cmp #$0A
    bcc cycle_spell_entity_blue_color_c135b3
    .a8
    lda #$00
cycle_spell_entity_blue_color_c135b3:
    sta a:$0022,Y
    sec
    .a8
    sbc #$05
    bcs cycle_spell_entity_blue_color_c135be
    .a8
    eor #$FF
    inc
cycle_spell_entity_blue_color_c135be:
    asl
    asl
    .a8
    ora #$20
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
    pla
    pla
    plp
    pld
    rts
