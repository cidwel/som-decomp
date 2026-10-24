; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

copy_spell_entity_sprite_record_words = $4297
queue_spell_entity_sprite_slot_write = $41F8

.segment "CODE"
.org $3527
advance_spell_entity_three_frame_tiles:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sty $01
    tyx
    lda a:$0016,X
    inc
    .a16
    cmp #$0003
    bcc advance_spell_entity_three_frame_tiles_c1353d
    .a16
    lda #$0000
advance_spell_entity_three_frame_tiles_c1353d:
    sta a:$0016,X
    asl
    asl
    clc
    adc a:$0016,X
    asl
    clc
    adc a:$001A,X
    tay
    lda a:$0018,X
    .a16
    and #$000F
    asl
    clc
    adc a:$0000,X
    tax
    .a16
    lda #$D104
    jsr copy_spell_entity_sprite_record_words
    ldy $01
    ldx a:$0000,Y
    jsr queue_spell_entity_sprite_slot_write
    sep #$20
    pla
    pla
    plp
    pld
    rts
