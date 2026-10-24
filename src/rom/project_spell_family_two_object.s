; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94

.segment "CODE"
.org $FA25
project_spell_family_two_object:
    phd
    php
    rep #$20
    phb
    phx
    tsc
    tcd
    sep #$20
    lda a:$0024,X
    asl
    asl
    asl
    asl
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    .a16
    adc #$F8E7
    sec
    .a16
    sbc #$F800
    txy
    tax
    lda a:$0020,Y
    pha
    lda a:$0022,Y
    pha
    sep #$20
    .a8
    lda #$10
    sta $01
project_spell_family_two_object_dcfa54:
    sty $02
    jsl f:project_packed_spell_entity_sprite_record_long
    ldy $02
    iny
    iny
    dec $01
    bne project_spell_family_two_object_dcfa54
    ply
    ply
    pla
    pla
    pla
    plp
    pld
    rts
