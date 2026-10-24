; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A80
drain_spell_entity_transfer_queue_to_ppu:
    phd
    php
    rep #$20
    phb
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    lda a:$821C
    bne drain_spell_entity_transfer_queue_to_ppu_c12a99
    jmp drain_spell_entity_transfer_queue_to_ppu_c12b75
drain_spell_entity_transfer_queue_to_ppu_c12a99:
    phd
    .a16
    lda #$4300
    tcd
    lda a:$821C
    ldy a:$8214
drain_spell_entity_transfer_queue_to_ppu_c12aa4:
    pha
    phy
    ldx a:$0000,Y
    phx
    sep #$20
    .a8
    lda #$00
    sta f:$00420B
    lda a:$0000,X
    sta $70
    rep #$20
    lda a:$0001,X
    sta $71
    lda a:$0003,X
    sta $73
    lda a:$0005,X
    sta $75
    plx
    .a16
    lda #$2100
    tcd
    sep #$20
    lda a:$0009,X
    sta $15
    lda a:$000F,X
    .a8
    and #$07
    dec
    beq drain_spell_entity_transfer_queue_to_ppu_c12b05
    dec
    beq drain_spell_entity_transfer_queue_to_ppu_c12afe
    dec
    beq drain_spell_entity_transfer_queue_to_ppu_c12aed
    rep #$20
    lda a:$000A,X
    sta $02
    sep #$20
    bra drain_spell_entity_transfer_queue_to_ppu_c12b0e
drain_spell_entity_transfer_queue_to_ppu_c12aed:
    lda a:$000A,X
    sta $81
    lda a:$000B,X
    sta $82
    lda a:$000C,X
    sta $83
    bra drain_spell_entity_transfer_queue_to_ppu_c12b0e
drain_spell_entity_transfer_queue_to_ppu_c12afe:
    lda a:$000A,X
    sta $21
    bra drain_spell_entity_transfer_queue_to_ppu_c12b0e
drain_spell_entity_transfer_queue_to_ppu_c12b05:
    rep #$20
    lda a:$000A,X
    sta $16
    sep #$20
drain_spell_entity_transfer_queue_to_ppu_c12b0e:
    .a8
    lda #$80
    sta f:$00420B
    nop
    nop
    nop
    nop
    rep #$20
    ply
    iny
    iny
    .a16
    lda #$4300
    tcd
    sep #$20
    lda f:$002137
    lda f:$00213D
    xba
    lda f:$00213D
    rep #$20
    .a16
    cmp #$E000
    bcc drain_spell_entity_transfer_queue_to_ppu_c12b66
    lda f:$004212
    .a16
    bit #$0080
    beq drain_spell_entity_transfer_queue_to_ppu_c12b66
    lda $75
    bne drain_spell_entity_transfer_queue_to_ppu_c12b66
    pla
    dec
    beq drain_spell_entity_transfer_queue_to_ppu_c12b4b
    jmp drain_spell_entity_transfer_queue_to_ppu_c12aa4
drain_spell_entity_transfer_queue_to_ppu_c12b4b:
    pld
    sep #$20
    lda f:$004212
    .a8
    bit #$80
    bne drain_spell_entity_transfer_queue_to_ppu_c12b75
    lda a:$8210
    bne drain_spell_entity_transfer_queue_to_ppu_c12b75
    dec a:$821C
    .a8
    lda #$00
    sta f:$00420B
    bra drain_spell_entity_transfer_queue_to_ppu_c12b75
drain_spell_entity_transfer_queue_to_ppu_c12b66:
    stz $75
    pla
    sec
    sbc a:$821C
    .a16
    eor #$FFFF
    inc
    sta a:$821C
    pld
drain_spell_entity_transfer_queue_to_ppu_c12b75:
    rep #$20
    plb
    sep #$20
    pla
    pla
    pla
    plp
    pld
    rts
