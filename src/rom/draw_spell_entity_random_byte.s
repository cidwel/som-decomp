; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

public_random_byte_jump = $C00018

.segment "CODE"
.org $46B0
draw_spell_entity_random_byte:
    phd
    php
    rep #$20
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsl f:public_random_byte_jump
    plb
    plp
    pld
    rts
