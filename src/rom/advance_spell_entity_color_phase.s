; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514
get_spell_entity_register_shadow = $44A1

.segment "CODE"
.org $3637
advance_spell_entity_color_phase:
    phd
    php
    rep #$20
    sep #$20
    phy
    jsr get_spell_entity_register_shadow
    ply
    lda a:$0032,X
    .a8
    ora #$E0
    .a8
    cmp #$F7
    bcc advance_spell_entity_color_phase_c1365c
    .a8
    lda #$78
    sta a:$001E,Y
    lda a:$0010,Y
    .a8
    and #$0F
    .a8
    ora #$30
    sta a:$0010,Y
    bra advance_spell_entity_color_phase_c1366a
advance_spell_entity_color_phase_c1365c:
    inc
    pha
    .a8
    lda #$32
    jsr allocate_spell_entity_register_record
    pla
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
advance_spell_entity_color_phase_c1366a:
    plp
    pld
    rts
