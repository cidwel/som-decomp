; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_entity_twin_sprite_object = $2CC7
construct_spell_graphics_audio_resources_long = $C12E90

.segment "CODE"
.org $2C19
initialize_spell_entity_twin_family:
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
    sty $02
    stz $0A
    .a8
    lda #$FF
    sta $09
    .i16
    ldx #$FAFD
    lda a:$0025,Y
    .a8
    cmp #$01
    beq initialize_spell_entity_twin_family_c12c5d
    .i16
    ldx #$FB0D
    .a8
    cmp #$03
    beq initialize_spell_entity_twin_family_c12c5d
    lda a:$002C,Y
    beq initialize_spell_entity_twin_family_c12c4e
    .i16
    ldx #$FB2D
    bra initialize_spell_entity_twin_family_c12c5d
initialize_spell_entity_twin_family_c12c4e:
    .a8
    lda #$01
    sta $0A
    lda a:$0029,Y
    .a8
    and #$1E
    lsr
    sta $09
    .i16
    ldx #$FB1D
initialize_spell_entity_twin_family_c12c5d:
    jsl f:construct_spell_graphics_audio_resources_long
    stx $07
    ldy $02
    lda $0A
    sta a:$002C,Y
    rep #$20
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
initialize_spell_entity_twin_family_c12c8b:
    stx $04
    lda $09
    .a8
    cmp #$FF
    bne initialize_spell_entity_twin_family_c12c96
    lda a:$0000,X
initialize_spell_entity_twin_family_c12c96:
    ldx $07
    jsr construct_spell_entity_twin_sprite_object
    rep #$20
    txa
    ldx $04
    sta a:$0002,X
    .a16
    lda #$2C10
    sta a:$0004,X
    .a16
    lda #$2C0B
    sta a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    sep #$20
    dec $01
    bne initialize_spell_entity_twin_family_c12c8b
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
