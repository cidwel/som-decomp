; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_bank_long = $C12E7C
release_spell_entity_sprite_pointer_group_long = $C12EB9

.segment "CODE"
.org $FA08
release_spell_family_two_object:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    stx $01
    .a16
    lda #$0010
    jsl f:release_spell_entity_sprite_pointer_group_long
    ldx $01
    jsl f:release_spell_entity_heap_bank_long
    sep #$20
    pla
    pla
    plp
    pld
    rts
