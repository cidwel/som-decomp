; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

queue_spell_entity_sprite_slot_write = $41F8
rotate_spell_entity_words_backward = $433E

.segment "CODE"
.org $36D4
rotate_spell_entity_extra_sprite_words:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    .a16
    lda #$0002
    sta a:$0026,X
    txy
    .a16
    lda #$0007
    sta $01
rotate_spell_entity_extra_sprite_words_c136eb:
    iny
    iny
    sty $03
    ldx a:$0000,Y
    beq rotate_spell_entity_extra_sprite_words_c13708
    .a16
    lda #$0F01
    jsr rotate_spell_entity_words_backward
    ldy $03
    ldx a:$0000,Y
    jsr queue_spell_entity_sprite_slot_write
    ldy $03
    dec $01
    bne rotate_spell_entity_extra_sprite_words_c136eb
rotate_spell_entity_extra_sprite_words_c13708:
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
