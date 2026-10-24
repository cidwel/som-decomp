; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trail-init.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_entity_trail_sprite_object = $F8C2
construct_spell_graphics_audio_resources_long = $C12E90

.segment "CODE"
.org $F835
initialize_spell_entity_trail_sprites:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    sty $02
    .i16
    ldx #$FD4A
    jsl f:construct_spell_graphics_audio_resources_long
    stx $07
    txa
    ldx $02
    sta a:$001A,X
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
    lda a:$0024,X
    sta $06
    lda a:$0022,X
    sta $09
    lda a:$0020,X
    sta $0A
initialize_spell_entity_trail_sprites_d3f882:
    stx $04
    lda $06
    clc
    .a8
    adc #$40
    sta $06
    xba
    lda a:$0000,X
    ldx $07
    ldy $09
    jsr construct_spell_entity_trail_sprite_object
    rep #$20
    txa
    ldx $04
    sta a:$0002,X
    .a16
    lda #$480B
    sta a:$0004,X
    .a16
    lda #$4806
    sta a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    sep #$20
    dec $01
    bne initialize_spell_entity_trail_sprites_d3f882
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
