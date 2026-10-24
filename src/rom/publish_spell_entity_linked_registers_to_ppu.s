; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $453C
publish_spell_entity_linked_registers_to_ppu:
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
    .a16
    lda #$2100
    sta $01
    .a16
    lda #$0000
    sta $03
    .i16
    ldy #$842A
publish_spell_entity_linked_registers_to_ppu_c1455d:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq publish_spell_entity_linked_registers_to_ppu_c14598
    clc
    adc a:$8426
    tay
    pha
    lda a:$0000,Y
    .a16
    and #$00FF
    tax
    lda a:$0002,Y
    sep #$20
    txy
    bne publish_spell_entity_linked_registers_to_ppu_c14583
    ldx a:$8432
    sta a:$0000,X
    tyx
    .a8
    ora #$80
publish_spell_entity_linked_registers_to_ppu_c14583:
    sta [$01],Y
    lda f:$DCFC8E,X
    beq publish_spell_entity_linked_registers_to_ppu_c14593
    .a8
    cmp #$01
    bne publish_spell_entity_linked_registers_to_ppu_c14590
    iny
publish_spell_entity_linked_registers_to_ppu_c14590:
    xba
    sta [$01],Y
publish_spell_entity_linked_registers_to_ppu_c14593:
    ply
    rep #$20
    bra publish_spell_entity_linked_registers_to_ppu_c1455d
publish_spell_entity_linked_registers_to_ppu_c14598:
    .i16
    ldy #$842E
publish_spell_entity_linked_registers_to_ppu_c1459b:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq publish_spell_entity_linked_registers_to_ppu_c145d6
    clc
    adc a:$8426
    tay
    pha
    lda a:$0000,Y
    .a16
    and #$00FF
    tax
    lda a:$0002,Y
    sep #$20
    txy
    bne publish_spell_entity_linked_registers_to_ppu_c145c1
    ldx a:$8432
    sta a:$0000,X
    tyx
    .a8
    ora #$80
publish_spell_entity_linked_registers_to_ppu_c145c1:
    sta [$01],Y
    lda f:$DCFC8E,X
    beq publish_spell_entity_linked_registers_to_ppu_c145d1
    .a8
    cmp #$01
    bne publish_spell_entity_linked_registers_to_ppu_c145ce
    iny
publish_spell_entity_linked_registers_to_ppu_c145ce:
    xba
    sta [$01],Y
publish_spell_entity_linked_registers_to_ppu_c145d1:
    ply
    rep #$20
    bra publish_spell_entity_linked_registers_to_ppu_c1459b
publish_spell_entity_linked_registers_to_ppu_c145d6:
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
