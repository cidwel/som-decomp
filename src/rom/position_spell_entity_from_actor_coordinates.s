; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-instances.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $38EA
position_spell_entity_from_actor_coordinates:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
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
    and #$00FF
    asl
    xba
    txy
    tax
    lda f:$7EE045,X
    .a16
    and #$00FF
    sta $01
    lda f:$7EE020,X
    sta a:$0002,Y
    lda f:$7EE022,X
    sec
    sbc $01
    sec
    .a16
    sbc #$0008
    sta a:$0000,Y
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
