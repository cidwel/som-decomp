; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514
get_spell_entity_register_shadow = $44A1

.segment "CODE"
.org $3690
decrement_spell_entity_all_color_channels:
    phd
    php
    rep #$20
    sep #$20
    jsr get_spell_entity_register_shadow
    lda a:$0032,X
    .a8
    ora #$E0
    .a8
    cmp #$E0
    beq decrement_spell_entity_all_color_channels_c136b0
    dec
    pha
    .a8
    lda #$32
    jsr allocate_spell_entity_register_record
    pla
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
decrement_spell_entity_all_color_channels_c136b0:
    plp
    pld
    rts
