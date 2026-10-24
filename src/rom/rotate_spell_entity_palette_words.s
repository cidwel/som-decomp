; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

queue_spell_entity_sprite_slot_write = $41F8
rotate_spell_entity_words_backward = $433E

.segment "CODE"
.org $356D
rotate_spell_entity_palette_words:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    sty $01
    lda a:$0018,Y
    .a8
    and #$0F
    clc
    .a8
    adc #$04
    xba
    lda a:$0018,Y
    ldx a:$0000,Y
    jsr rotate_spell_entity_words_backward
    ldy $01
    ldx a:$0000,Y
    jsr queue_spell_entity_sprite_slot_write
    pla
    pla
    plp
    pld
    rts
