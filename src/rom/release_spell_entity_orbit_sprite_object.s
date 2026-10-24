; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_sprite_pointer_group_long = $C12EB9
routine_c12e7c = $C12E7C

.segment "CODE"
.org $F30A
release_spell_entity_orbit_sprite_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    stx $05
    .a16
    lda #$0008
    sta $03
release_spell_entity_orbit_sprite_object_d3f31c:
    phx
    .a16
    lda #$0002
    sta $01
release_spell_entity_orbit_sprite_object_d3f322:
    phx
    .a16
    lda #$0004
    jsl f:release_spell_entity_sprite_pointer_group_long
    plx
    clc
    txa
    .a16
    adc #$000C
    tax
    dec $01
    bne release_spell_entity_orbit_sprite_object_d3f322
    plx
    clc
    txa
    .a16
    adc #$001C
    tax
    dec $03
    bne release_spell_entity_orbit_sprite_object_d3f31c
    ldx $05
    jsl f:routine_c12e7c
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
