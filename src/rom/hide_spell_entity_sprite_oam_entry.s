; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-projection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4090
hide_spell_entity_sprite_oam_entry:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    .a16
    lda #$FFF0
    sta a:$0002,X
    stz a:$0004,X
    lda a:$000A,X
    .a16
    and #$00FF
    asl
    asl
    clc
    adc a:$841E
    tax
    sep #$20
    .a8
    lda #$F0
    sta a:$0001,X
    plb
    plp
    pld
    rts
