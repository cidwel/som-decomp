; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-topology.md.
.setcpu "65816"
.smart
.a8
.i16

construct_boss_spell_entity_sprite_pointer_set = $3113
construct_spell_entity_sprite_pointer_set = $31E4
queue_spell_entity_sprite_slot_read = $4240
save_spell_entity_sprite_slot_shadow = $43B6
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $3297
prepare_spell_entity_sprite_pointer_transfers:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    lda $06,S
    sep #$20
    stx $02
    sty $04
    sta $01
    lda a:$0000,Y
    rep #$20
    .a16
    and #$00FF
    xba
    asl
    tax
    sep #$20
    lda f:$7EE180,X
    .a8
    cmp #$57
    bcc prepare_spell_entity_sprite_pointer_transfers_c132cf
    .a8
    cmp #$80
    bcs prepare_spell_entity_sprite_pointer_transfers_c132cf
    lda $01
    ldx $02
    jsr construct_boss_spell_entity_sprite_pointer_set
    bra prepare_spell_entity_sprite_pointer_transfers_c132d6
prepare_spell_entity_sprite_pointer_transfers_c132cf:
    lda $01
    ldx $02
    jsr construct_spell_entity_sprite_pointer_set
prepare_spell_entity_sprite_pointer_transfers_c132d6:
    ldy $02
    .a8
    lda #$08
    sta $06
prepare_spell_entity_sprite_pointer_transfers_c132dc:
    ldx a:$0000,Y
    beq prepare_spell_entity_sprite_pointer_transfers_c132e6
    phy
    jsr queue_spell_entity_sprite_slot_read
    ply
prepare_spell_entity_sprite_pointer_transfers_c132e6:
    iny
    iny
    dec $06
    bne prepare_spell_entity_sprite_pointer_transfers_c132dc
    jsr wait_for_spell_entity_irq_completion
    ldy $02
    .a8
    lda #$08
    sta $06
prepare_spell_entity_sprite_pointer_transfers_c132f5:
    ldx a:$0000,Y
    beq prepare_spell_entity_sprite_pointer_transfers_c132ff
    phy
    jsr save_spell_entity_sprite_slot_shadow
    ply
prepare_spell_entity_sprite_pointer_transfers_c132ff:
    iny
    iny
    dec $06
    bne prepare_spell_entity_sprite_pointer_transfers_c132f5
    ldx $02
    rep #$20
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
