; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-slots.md.
.setcpu "65816"
.smart
.a8
.i16

service_pending_spell_entity_transfer_requests = $2A1E
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $2896
allocate_spell_entity_actor_slot:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    pha
    sep #$20
allocate_spell_entity_actor_slot_c128ad:
    ldx a:$8212
    .i16
    ldy #$0020
allocate_spell_entity_actor_slot_c128b3:
    lda a:$000F,X
    beq allocate_spell_entity_actor_slot_c128cd
    clc
    rep #$20
    txa
    .a16
    adc #$0010
    tax
    sep #$20
    dey
    bne allocate_spell_entity_actor_slot_c128b3
    jsr service_pending_spell_entity_transfer_requests
    jsr wait_for_spell_entity_irq_completion
    bra allocate_spell_entity_actor_slot_c128ad
allocate_spell_entity_actor_slot_c128cd:
    rep #$20
    pla
    sep #$20
    sta a:$000F,X
    xba
    sta a:$000D,X
    phx
    .a8
    cmp #$00
    beq allocate_spell_entity_actor_slot_c128f4
    .a8
    cmp #$20
    beq allocate_spell_entity_actor_slot_c128e4
    bcs allocate_spell_entity_actor_slot_c128f4
allocate_spell_entity_actor_slot_c128e4:
    dec
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$8216
    tax
    sep #$20
    inc a:$0000,X
allocate_spell_entity_actor_slot_c128f4:
    plx
    .a8
    lda #$00
    xba
    lda a:$000F,X
    .a8
    and #$07
    dec
    txy
    tax
    lda f:$DCF838,X
    sta a:$0000,Y
    lda f:$DCF83D,X
    sta a:$0009,Y
    lda f:$DCF842,X
    sta a:$0001,Y
    tyx
    lda a:$000F,X
    .a8
    cmp #$05
    bne allocate_spell_entity_actor_slot_c1291d
allocate_spell_entity_actor_slot_c1291d:
    plb
    pla
    pla
    plp
    pld
    rts
