; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94

.segment "CODE"
.org $2D63
publish_spell_entity_twin_sprite_group:
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
    lda a:$0018,X
    sta $01
    asl
    asl
    clc
    adc $01
    asl
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    .a16
    adc #$FB3D
    sec
    .a16
    sbc #$F800
    txy
    tax
    lda a:$0014,Y
    pha
    lda a:$0016,Y
    pha
    sep #$20
    .a8
    lda #$0A
    sta $04
publish_spell_entity_twin_sprite_group_c12d99:
    sty $02
    jsl f:project_packed_spell_entity_sprite_record_long
    ldy $02
    iny
    iny
    dec $04
    bne publish_spell_entity_twin_sprite_group_c12d99
    ply
    ply
    pla
    pla
    pla
    pla
    plp
    pld
    rts
