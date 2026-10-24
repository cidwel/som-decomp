; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3C04
allocate_spell_entity_heap_units:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    lda $06,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    sta $02
    stz $03
    .a8
    lda #$01
    sta $07
    ldx a:$8238
    stx $04
    .a8
    lda #$F0
    sec
    sbc a:$8238
    sta $01
    lda $02
    sta $06
allocate_spell_entity_heap_units_c13c34:
    lda a:$823A,X
    bne allocate_spell_entity_heap_units_c13c3f
    dec $06
    beq allocate_spell_entity_heap_units_c13c4f
    bra allocate_spell_entity_heap_units_c13c45
allocate_spell_entity_heap_units_c13c3f:
    lda $02
    sta $06
    stx $04
allocate_spell_entity_heap_units_c13c45:
    inx
    dec $01
    bne allocate_spell_entity_heap_units_c13c34
    .i16
    ldx #$0000
    bra allocate_spell_entity_heap_units_c13cac
allocate_spell_entity_heap_units_c13c4f:
    .a8
    lda #$F0
    sec
    sbc $01
    cmp a:$8236
    beq allocate_spell_entity_heap_units_c13c5e
    bcc allocate_spell_entity_heap_units_c13c5e
    sta a:$8236
allocate_spell_entity_heap_units_c13c5e:
    rep #$20
    lda $04
    cmp a:$8238
    bne allocate_spell_entity_heap_units_c13c82
    clc
    adc $02
    tay
    sep #$20
allocate_spell_entity_heap_units_c13c6d:
    lda a:$823A,Y
    beq allocate_spell_entity_heap_units_c13c7a
    iny
    dec $01
    bne allocate_spell_entity_heap_units_c13c6d
    .i16
    ldy #$0000
allocate_spell_entity_heap_units_c13c7a:
    sty a:$8238
    rep #$20
    lda $04
    dec
allocate_spell_entity_heap_units_c13c82:
    inc
    tax
    sta $04
    sep #$20
    lda $02
    sta $01
allocate_spell_entity_heap_units_c13c8c:
    lda $01
    sta a:$823A,X
    lda $07
    sta a:$832A,X
    inx
    dec $01
    bne allocate_spell_entity_heap_units_c13c8c
    rep #$20
    lda $04
    asl
    asl
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$8200
    tax
    sep #$20
allocate_spell_entity_heap_units_c13cac:
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
