; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-oam.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48
project_spell_entity_sprite_record_to_oam = $3E9C

.segment "CODE"
.org $3D8F
initialize_spell_entity_oam_workspace:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    pha
    .a8
    and #$02
    sta a:$8421
    pla
    .a8
    and #$01
    sta a:$8420
    xba
    sta $03
    stz a:$8422
    .a8
    lda #$00
    .i16
    ldx #$0400
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx a:$841A
    .i16
    ldx #$0800
    stx a:$841E
    .a8
    lda #$00
    .i16
    ldx #$0100
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx a:$841C
    ldx a:$841A
    .a8
    lda #$40
    sta $01
initialize_spell_entity_oam_workspace_c13ddb:
    phx
    rep #$20
    .a16
    lda #$FFF0
    sta a:$0002,X
    stz a:$0004,X
    sep #$20
    .a8
    lda #$40
    sec
    sbc $01
    sta a:$000A,X
    lda $03
    lsr
    lsr
    sta a:$000B,X
    stz a:$0008,X
    jsr project_spell_entity_sprite_record_to_oam
    plx
    clc
    rep #$20
    txa
    .a16
    adc #$0010
    tax
    sep #$20
    dec $01
    bne initialize_spell_entity_oam_workspace_c13ddb
    ldx a:$841C
    ldy a:$841A
    rep #$20
    .a16
    lda #$0010
    sta $01
initialize_spell_entity_oam_workspace_c13e1a:
    tya
    sta a:$0000,X
    tay
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sta a:$0002,X
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sta a:$0004,X
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sta a:$0006,X
    txa
    sta a:$000C,Y
    clc
    tya
    .a16
    adc #$0010
    tay
    sep #$20
    .a8
    lda #$10
    sec
    sbc $01
    asl
    asl
    sta a:$0009,X
    asl
    sta a:$000A,X
    lda $03
    sta a:$000B,X
    rep #$20
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $01
    bne initialize_spell_entity_oam_workspace_c13e1a
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
