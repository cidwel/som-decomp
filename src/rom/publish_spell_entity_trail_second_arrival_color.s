; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record_long = $C12ED5
append_spell_entity_transient_register_record_long = $C12ED9

.segment "CODE"
.org $FCD3
publish_spell_entity_trail_second_arrival_color:
    phd
    php
    rep #$20
    sep #$20
    phy
    .a8
    lda #$31
    jsl f:allocate_spell_entity_register_record_long
    .a8
    lda #$83
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
