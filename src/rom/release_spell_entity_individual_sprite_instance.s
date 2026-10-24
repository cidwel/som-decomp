; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-instances.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $40BE
release_spell_entity_individual_sprite_instance:
    phd
    php
    rep #$20
    .a16
    lda #$FFF0
    sta a:$0002,X
    stz a:$0004,X
    stz a:$0008,X
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
    plp
    pld
    rts
