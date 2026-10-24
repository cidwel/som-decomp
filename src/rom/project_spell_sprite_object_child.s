; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-motion.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94

.segment "CODE"
.org $EF74
project_spell_sprite_object_child:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    sta $01
    asl
    clc
    adc $01
    clc
    adc a:$0006,X
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    .a16
    adc #$F859
    sec
    .a16
    sbc #$F800
    txy
    tax
    lda a:$0002,Y
    pha
    lda a:$0004,Y
    pha
    jsl f:project_packed_spell_entity_sprite_record_long
    pla
    pla
    sep #$20
    pla
    plp
    pld
    rts
