; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resource-state.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514
queue_spell_entity_sprite_slot_write = $41F8
release_selected_spell_entity_sprite_pointers = $30E2
release_spell_entity_heap_with_saved_bank = $3D7D
restore_spell_entity_sprite_slot_shadow = $43D3
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $345A
release_spell_entity_visual_resource:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    stx $04
    sty $06
    txy
    .a8
    lda #$04
    sta $01
release_spell_entity_visual_resource_c13475:
    sty $02
    ldx a:$0000,Y
    beq release_spell_entity_visual_resource_c1348f
    jsr restore_spell_entity_sprite_slot_shadow
    ldy $02
    ldx a:$0000,Y
    jsr queue_spell_entity_sprite_slot_write
    ldy $02
    iny
    iny
    dec $01
    bne release_spell_entity_visual_resource_c13475
release_spell_entity_visual_resource_c1348f:
    ldx $04
    lda a:$0024,X
    beq release_spell_entity_visual_resource_c134c6
    ldx $06
    lda a:$002C,X
    bne release_spell_entity_visual_resource_c134c6
    .a8
    lda #$30
    jsr allocate_spell_entity_register_record
    .a8
    lda #$02
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
    .a8
    lda #$31
    jsr allocate_spell_entity_register_record
    lda f:$000023
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
    .a8
    lda #$32
    jsr allocate_spell_entity_register_record
    .a8
    lda #$E0
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
release_spell_entity_visual_resource_c134c6:
    jsr wait_for_spell_entity_irq_completion
    .a8
    lda #$FF
    ldx $04
    jsr release_selected_spell_entity_sprite_pointers
    ldx $04
    jsr release_spell_entity_heap_with_saved_bank
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
