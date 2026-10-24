; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-engine.md.
.setcpu "65816"
.smart
.a8
.i16

construct_temporary_spell_entity = $39CD
release_native_spell_entity_scheduler_callbacks = $3AC5
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $3B3C
execute_native_spell_entity_scheduler:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$000A
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    txa
    .a16
    and #$1E00
    clc
    .a16
    adc #$E000
    tax
    jsr construct_temporary_spell_entity
    .i16
    cpx #$0000
    beq execute_native_spell_entity_scheduler_c13bc1
    stx $03
execute_native_spell_entity_scheduler_c13b63:
    jsr wait_for_spell_entity_irq_completion
    ldx $03
    lda a:$0025,X
    .a16
    and #$00FF
    asl
    txy
    tax
    jsr ($3B2E,X)
    ldx $03
    lda a:$002A,X
    sta $01
    jsr wait_for_spell_entity_irq_completion
execute_native_spell_entity_scheduler_c13b7e:
    ldx $03
    .a16
    lda #$00FF
    sta $09
    .a16
    lda #$0004
    sta $07
    txa
    clc
    .a16
    adc #$0000
execute_native_spell_entity_scheduler_c13b8f:
    sta $05
    tay
    lda a:$0004,Y
    beq execute_native_spell_entity_scheduler_c13ba0
    pea a:$3B9F
    ldx a:$0002,Y
    dec
    pha
    rts
execute_native_spell_entity_scheduler_c13ba0:
    .a16
    eor #$00FF
    and $09
    sta $09
    lda $05
    clc
    .a16
    adc #$0008
    dec $07
    bne execute_native_spell_entity_scheduler_c13b8f
    jsr wait_for_spell_entity_irq_completion
    lda $09
    .a16
    and #$00FF
    bne execute_native_spell_entity_scheduler_c13bbf
    dec $01
    bne execute_native_spell_entity_scheduler_c13b7e
execute_native_spell_entity_scheduler_c13bbf:
    ldx $03
execute_native_spell_entity_scheduler_c13bc1:
    jsr release_native_spell_entity_scheduler_callbacks
    .i16
    cpx #$0000
    bne execute_native_spell_entity_scheduler_c13b63
    plb
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts
