; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514
get_spell_entity_register_shadow = $44A1

.segment "CODE"
.org $35CD
increment_spell_entity_two_color_channels:
    phd
    php
    rep #$20
    sep #$20
    jsr get_spell_entity_register_shadow
    lda a:$0032,X
    .a8
    and #$1F
    .a8
    cmp #$17
    bcs increment_spell_entity_two_color_channels_c135ef
    inc
    .a8
    ora #$C0
    pha
    .a8
    lda #$32
    jsr allocate_spell_entity_register_record
    pla
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
increment_spell_entity_two_color_channels_c135ef:
    plp
    pld
    rts
