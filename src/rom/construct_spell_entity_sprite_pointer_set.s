; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-topology.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_sprite_slot = $41A5
release_selected_spell_entity_sprite_pointers = $30E2

.segment "CODE"
.org $31E4
construct_spell_entity_sprite_pointer_set:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0009
    tcd
    tcs
    lda $0A,S
    sep #$20
    stx $02
    sty $04
    sta $01
    rep #$20
    .a16
    lda #$0008
    sta $08
construct_spell_entity_sprite_pointer_set_c13201:
    stx $06
    .a16
    lda #$0008
    jsr allocate_spell_entity_sprite_slot
    txa
    ldx $06
    sta a:$0000,X
    inx
    inx
    dec $08
    bne construct_spell_entity_sprite_pointer_set_c13201
    ldx $02
    lda $01
    .a16
    and #$00FF
    .a16
    cmp #$00C0
    bcc construct_spell_entity_sprite_pointer_set_c1324b
    .a16
    lda #$00E1
    jsr release_selected_spell_entity_sprite_pointers
    lda a:$0008,X
    sta a:$0000,X
    lda a:$0002,X
    sta a:$000A,X
    lda a:$0004,X
    sta a:$000C,X
    lda a:$0006,X
    sta a:$000E,X
    stz a:$0002,X
    stz a:$0004,X
    stz a:$0006,X
    stz a:$0008,X
construct_spell_entity_sprite_pointer_set_c1324b:
    .a16
    lda #$001E
    jsr release_selected_spell_entity_sprite_pointers
    ldy $02
    iny
    iny
    ldx $04
    lda a:$0027,X
    .a16
    and #$00FF
    sta $08
construct_spell_entity_sprite_pointer_set_c1325f:
    stx $0A
    lda a:$0000,X
    .a16
    and #$0007
    dec
    dec
    asl
    clc
    adc $02
    tax
    lda a:$0008,X
    beq construct_spell_entity_sprite_pointer_set_c1327b
    sta a:$0000,Y
    stz a:$0008,X
    iny
    iny
construct_spell_entity_sprite_pointer_set_c1327b:
    lda $0A
    clc
    .a16
    adc #$0008
    tax
    dec $08
    bne construct_spell_entity_sprite_pointer_set_c1325f
    ldx $02
    .a16
    lda #$00F0
    jsr release_selected_spell_entity_sprite_pointers
    tsc
    clc
    .a16
    adc #$000B
    tcs
    plp
    pld
    rts
