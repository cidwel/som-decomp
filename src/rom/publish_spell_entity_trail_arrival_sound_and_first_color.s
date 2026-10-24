; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record_long = $C12ED5
append_spell_entity_transient_register_record_long = $C12ED9
send_spell_entity_positional_sound_long = $C12EBD

.segment "CODE"
.org $FCA7
publish_spell_entity_trail_arrival_sound_and_first_color:
    phd
    php
    rep #$20
    sep #$20
    phy
    lda a:$0142,X
    xba
    .a8
    lda #$C1
    jsl f:send_spell_entity_positional_sound_long
    .a8
    lda #$31
    jsl f:allocate_spell_entity_register_record_long
    .a8
    lda #$03
    sta a:$0002,X
    jsl f:append_spell_entity_transient_register_record_long
    plx
    .a8
    lda #$01
    sta a:$0152,X
    inc a:$0154,X
    plp
    pld
    rts
