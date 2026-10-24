; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-orbit-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_entity_orbit_sprite_object = $F287
routine_c12e90 = $C12E90

.segment "CODE"
.org $F22C
initialize_spell_entity_orbit_sprites:
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
    rep #$20
    sty $01
    .i16
    ldx #$FC32
    jsl f:routine_c12e90
    stx $03
    txa
    ldx $01
    sta a:$001A,X
    .a16
    lda #$00EB
    sta a:$002A,X
    .a16
    lda #$3711
    sta a:$001C,X
    .a16
    lda #$345A
    sta a:$001E,X
    lda a:$0000,X
    ldx $03
    jsr construct_spell_entity_orbit_sprite_object
    txa
    ldx $01
    sta a:$0002,X
    .a16
    lda #$2EE7
    sta a:$0004,X
    .a16
    lda #$2EE2
    sta a:$0006,X
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
