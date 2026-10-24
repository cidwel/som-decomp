; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_sprite_pointer_group_long = $C12EB9
routine_c12e7c = $C12E7C

.segment "CODE"
.org $2D38
release_spell_entity_twin_sprite_object:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    stx $01
    .a16
    lda #$000A
    jsl f:release_spell_entity_sprite_pointer_group_long
    lda $01
    clc
    .a16
    adc #$001A
    tax
    .a16
    lda #$000A
    jsl f:release_spell_entity_sprite_pointer_group_long
    ldx $01
    jsl f:routine_c12e7c
    sep #$20
    pla
    pla
    plp
    pld
    rts
