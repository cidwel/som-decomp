; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-transfers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $41A5
allocate_spell_entity_sprite_slot:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    .a16
    and #$000F
    asl
    asl
    asl
    asl
    asl
    clc
    adc a:$8424
    tax
    .i16
    ldy #$0008
allocate_spell_entity_sprite_slot_c141c4:
    .a16
    lda #$8000
    bit a:$0000,X
    bne allocate_spell_entity_sprite_slot_c141da
    clc
    txa
    .a16
    adc #$0020
    tax
    dey
    bne allocate_spell_entity_sprite_slot_c141c4
    .i16
    ldx #$0000
    bra allocate_spell_entity_sprite_slot_c141dd
allocate_spell_entity_sprite_slot_c141da:
    stz a:$0000,X
allocate_spell_entity_sprite_slot_c141dd:
    plb
    plp
    pld
    rts
