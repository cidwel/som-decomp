; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-graphics-audio.md.
.setcpu "65816"
.smart
.a8
.i16

routine_018009 = $18009

.segment "CODE"
.org $3007
convert_spell_entity_graphics_planes:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$D4
    pha
    plb
    pla
    rep #$20
    pha
    .a16
    lda #$0000
    tcd
    sec
    txa
    .a16
    sbc #$2000
    tax
    pla
    sep #$20
    jsl f:routine_018009
    plb
    plp
    pld
    rts
