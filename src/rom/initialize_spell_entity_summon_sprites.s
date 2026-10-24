; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-summon-init.md.
.setcpu "65816"
.smart
.a8
.i16

construct_temporary_spell_sprite_object = $ED5F
routine_c12e90 = $C12E90

.segment "CODE"
.org $EE60
initialize_spell_entity_summon_sprites:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0008
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
    ldx #$F8A3
    jsl f:routine_c12e90
    stx $07
    inc a:$0012,X
    txa
    ldx $02
    sta a:$001A,X
    .a16
    lda #$00F0
    sta a:$002A,X
    .a16
    lda #$3711
    sta a:$001C,X
    .a16
    lda #$345A
    sta a:$001E,X
    sep #$20
    .a8
    lda #$C0
    sta $06
    lda a:$0027,X
    sta $01
    clc
    rep #$20
    txa
    .a16
    adc #$0000
    tax
    sep #$20
initialize_spell_entity_summon_sprites_d3eeaf:
    stx $04
    lda a:$0000,X
    xba
    ldx $02
    lda a:$0024,X
    clc
    adc $06
    tay
    lda a:$0020,X
    xba
    lda a:$0022,X
    rep #$20
    tax
    tya
    ldy $07
    jsr construct_temporary_spell_sprite_object
    txa
    ldx $04
    sta a:$0002,X
    .a16
    lda #$2BED
    sta a:$0004,X
    .a16
    lda #$2BF2
    sta a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    sep #$20
    lda $06
    clc
    .a8
    adc #$40
    sta $06
    dec $01
    bne initialize_spell_entity_summon_sprites_d3eeaf
    ldx $02
    ldy a:$0002,X
    .a8
    lda #$02
    sta a:$023D,Y
    ldy a:$000A,X
    bne initialize_spell_entity_summon_sprites_d3ef2c
    lda a:$0020,X
    xba
    lda a:$0022,X
    tay
    lda a:$0008,X
    xba
    lda a:$0024,X
    tyx
    jsr construct_temporary_spell_sprite_object
    rep #$20
    txa
    ldx $02
    sta a:$000A,X
    tay
    .a16
    lda #$2BED
    sta a:$000C,X
    .a16
    lda #$2BF2
    sta a:$000E,X
    sep #$20
initialize_spell_entity_summon_sprites_d3ef2c:
    .a8
    lda #$03
    sta a:$023D,Y
    ldy a:$0012,X
    bne initialize_spell_entity_summon_sprites_d3ef63
    lda a:$0020,X
    xba
    lda a:$0022,X
    tay
    lda a:$0010,X
    xba
    lda a:$0024,X
    clc
    .a8
    adc #$40
    tyx
    jsr construct_temporary_spell_sprite_object
    rep #$20
    txa
    ldx $02
    sta a:$0012,X
    tay
    .a16
    lda #$2BED
    sta a:$0014,X
    .a16
    lda #$2BF2
    sta a:$0016,X
    sep #$20
initialize_spell_entity_summon_sprites_d3ef63:
    .a8
    lda #$06
    sta a:$023D,Y
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
