; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-init.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_entity_burst_sprite_object = $EB83
construct_spell_graphics_audio_resources_long = $C12E90
initialize_spell_entity_twin_family_long = $C12C15

.segment "CODE"
.org $EA04
initialize_spell_entity_burst_sprites:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    lda a:$002C,Y
    beq initialize_spell_entity_burst_sprites_d3ea28
    phy
    jsl f:initialize_spell_entity_twin_family_long
    plx
    stz a:$002C,X
    bra initialize_spell_entity_burst_sprites_d3ea87
initialize_spell_entity_burst_sprites_d3ea28:
    sty $02
    .i16
    ldx #$F81E
    jsl f:construct_spell_graphics_audio_resources_long
    stx $06
    txa
    ldx $02
    sta a:$001A,X
    .a16
    lda #$0001
    sta a:$002C,X
    .a16
    lda #$0000
    sta a:$002A,X
    .a16
    lda #$3711
    sta a:$001C,X
    .a16
    lda #$345A
    sta a:$001E,X
    sep #$20
    lda a:$0027,X
    sta $01
initialize_spell_entity_burst_sprites_d3ea58:
    stx $04
    lda a:$0000,X
    ldx $06
    jsr construct_spell_entity_burst_sprite_object
    lda $01
    sta a:$0056,X
    rep #$20
    txa
    ldx $04
    sta a:$0002,X
    .a16
    lda #$2805
    sta a:$0004,X
    .a16
    lda #$280A
    sta a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    sep #$20
    dec $01
    bne initialize_spell_entity_burst_sprites_d3ea58
initialize_spell_entity_burst_sprites_d3ea87:
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
