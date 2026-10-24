; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-transfers.md.
.setcpu "65816"
.smart
.a8
.i16

copy_native_entity_memory_bytes = $4761

.segment "CODE"
.org $43B6
save_spell_entity_sprite_slot_shadow:
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
    txa
    clc
    .a16
    adc #$0200
    tay
    .a16
    lda #$0020
    jsr copy_native_entity_memory_bytes
    plb
    plp
    pld
    rts
