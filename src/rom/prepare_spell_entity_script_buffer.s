; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-construction.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_heap_bytes = $3D29
build_spell_entity_script_transfers = $302E

.segment "CODE"
.org $39A1
prepare_spell_entity_script_buffer:
    phd
    php
    rep #$20
    .i16
    ldx #$0380
    jsr allocate_spell_entity_heap_bytes
    stx a:$8234
    .i16
    ldy #$FC6A
    .a16
    lda #$0006
    jsr build_spell_entity_script_transfers
    plp
    pld
    rts
