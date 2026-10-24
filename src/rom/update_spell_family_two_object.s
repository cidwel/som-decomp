; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

project_spell_family_two_object = $FA25

.segment "CODE"
.org $FA6E
update_spell_family_two_object:
    phd
    php
    rep #$20
    sep #$20
    phx
    jsr project_spell_family_two_object
    plx
    lda a:$0024,X
    inc
    .a8
    cmp #$02
    bcc update_spell_family_two_object_dcfa83
    .a8
    lda #$00
update_spell_family_two_object_dcfa83:
    sta a:$0024,X
    .a8
    lda #$FF
    plp
    pld
    rts
