; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-topology.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48
allocate_spell_entity_sprite_slot = $41A5
release_spell_entity_sprite_slot = $41E1

.segment "CODE"
.org $3113
construct_boss_spell_entity_sprite_pointer_set:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    lda $0C,S
    sep #$20
    sta $01
    stx $02
    sty $04
    lda a:$0000,Y
    rep #$20
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    sta $08
    .i16
    ldx #$0020
    .a16
    lda #$0000
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx $06
    .a16
    lda #$0008
    sta $0A
construct_boss_spell_entity_sprite_pointer_set_c13149:
    stx $0C
    .a16
    lda #$0000
    jsr allocate_spell_entity_sprite_slot
    txa
    ldx $0C
    sta a:$0000,X
    inx
    inx
    dec $0A
    bne construct_boss_spell_entity_sprite_pointer_set_c13149
    .a16
    lda #$0008
    sta $0A
construct_boss_spell_entity_sprite_pointer_set_c13162:
    stx $0C
    .a16
    lda #$0008
    jsr allocate_spell_entity_sprite_slot
    txa
    ldx $0C
    sta a:$0000,X
    inx
    inx
    dec $0A
    bne construct_boss_spell_entity_sprite_pointer_set_c13162
    ldx $06
    ldy $02
    lda $01
    .a16
    and #$00FF
    .a16
    cmp #$00C0
    bcc construct_boss_spell_entity_sprite_pointer_set_c1318f
    lda a:$0018,X
    sta a:$0000,Y
    stz a:$0018,X
    bra construct_boss_spell_entity_sprite_pointer_set_c13198
construct_boss_spell_entity_sprite_pointer_set_c1318f:
    lda a:$0010,X
    sta a:$0000,Y
    stz a:$0010,X
construct_boss_spell_entity_sprite_pointer_set_c13198:
    iny
    iny
    sty $0C
    .a16
    lda #$0004
    sta $0A
construct_boss_spell_entity_sprite_pointer_set_c131a1:
    ldx $08
    lda a:$0018,X
    inx
    stx $08
    .a16
    and #$00FF
    beq construct_boss_spell_entity_sprite_pointer_set_c131c0
    asl
    clc
    adc $06
    tax
    lda a:$0000,X
    beq construct_boss_spell_entity_sprite_pointer_set_c131c0
    sta a:$0000,Y
    iny
    iny
    stz a:$0000,X
construct_boss_spell_entity_sprite_pointer_set_c131c0:
    dec $0A
    bne construct_boss_spell_entity_sprite_pointer_set_c131a1
    ldy $06
    .a16
    lda #$0010
    sta $0A
construct_boss_spell_entity_sprite_pointer_set_c131cb:
    ldx a:$0000,Y
    beq construct_boss_spell_entity_sprite_pointer_set_c131d5
    phy
    jsr release_spell_entity_sprite_slot
    ply
construct_boss_spell_entity_sprite_pointer_set_c131d5:
    iny
    iny
    dec $0A
    bne construct_boss_spell_entity_sprite_pointer_set_c131cb
    tsc
    clc
    .a16
    adc #$000D
    tcs
    plp
    pld
    rts
