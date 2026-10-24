; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-engine.md.
.setcpu "65816"
.smart
.a8
.i16

queue_spell_entity_script_cleanup = $39BA
release_spell_entity_heap_with_saved_bank = $3D7D
restore_spell_entity_irq_handler = $2F33
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $3AC5
release_native_spell_entity_scheduler_callbacks:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    .i16
    cpx #$0000
    beq release_native_spell_entity_scheduler_callbacks_c13b19
    stx $03
    .a16
    lda #$0004
    sta $01
    clc
    txa
    .a16
    adc #$0000
    tax
release_native_spell_entity_scheduler_callbacks_c13ae2:
    stx $05
    lda a:$0006,X
    beq release_native_spell_entity_scheduler_callbacks_c13af5
    pea a:$3AF4
    txy
    ldx a:$0002,Y
    ldy $03
    dec
    pha
    rts
release_native_spell_entity_scheduler_callbacks_c13af5:
    ldx $05
    stz a:$0004,X
    stz a:$0002,X
    stz a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    dec $01
    bne release_native_spell_entity_scheduler_callbacks_c13ae2
    ldx $03
    lda a:$002C,X
    bne release_native_spell_entity_scheduler_callbacks_c13b25
    ldx $03
    jsr release_spell_entity_heap_with_saved_bank
    jsr wait_for_spell_entity_irq_completion
release_native_spell_entity_scheduler_callbacks_c13b19:
    jsr queue_spell_entity_script_cleanup
    jsr wait_for_spell_entity_irq_completion
    jsr restore_spell_entity_irq_handler
    .i16
    ldx #$0000
release_native_spell_entity_scheduler_callbacks_c13b25:
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
