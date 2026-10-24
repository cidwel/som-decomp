; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_heap_bytes = $3D48
allocate_spell_entity_register_record = $44B3
append_spell_entity_transient_register_record = $4514
copy_spell_entity_sprite_record_words = $4297
prepare_spell_entity_sprite_pointer_transfers = $3297
queue_spell_entity_sprite_slot_write = $41F8
wait_for_spell_entity_irq_completion = $2FE4

.segment "CODE"
.org $332C
construct_spell_entity_visual_resource:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$000E
    tcd
    tcs
    stx $05
    sty $07
    lda a:$0026,Y
    .a16
    and #$0004
    asl
    asl
    asl
    asl
    sta $01
    lda a:$0028,Y
    .a16
    and #$0600
    lsr
    xba
    sep #$20
    xba
    .a8
    lda #$05
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    inc
    clc
    adc $01
    sta $01
    .a16
    lda #$0000
    .i16
    ldx #$0028
    jsr allocate_and_fill_spell_entity_heap_bytes
    stx $03
    ldx $05
    ldy $03
    sep #$20
    lda f:$DCF80B,X
    sta a:$0024,Y
    beq construct_spell_entity_visual_resource_c133bb
    .a8
    and #$C0
    .a8
    ora #$03
    sta $0E
    lda a:$0024,Y
    .a8
    ora #$E0
    sta $0D
    ldx $07
    lda a:$002C,X
    bne construct_spell_entity_visual_resource_c133bb
    .a8
    lda #$30
    jsr allocate_spell_entity_register_record
    .a8
    lda #$00
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
    .a8
    lda #$31
    jsr allocate_spell_entity_register_record
    lda $0E
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
    .a8
    lda #$32
    jsr allocate_spell_entity_register_record
    lda $0D
    sta a:$0002,X
    jsr append_spell_entity_transient_register_record
construct_spell_entity_visual_resource_c133bb:
    jsr wait_for_spell_entity_irq_completion
    rep #$20
    ldy $07
    ldx $03
    lda $01
    jsr prepare_spell_entity_sprite_pointer_transfers
    ldx $05
    lda f:$DCF80C,X
    sta $0B
    ldx $07
    lda a:$0027,X
    .a16
    and #$00FF
    sta $09
    ldy $03
construct_spell_entity_visual_resource_c133dd:
    iny
    iny
    ldx a:$0000,Y
    beq construct_spell_entity_visual_resource_c133f4
    phy
    ldy $0B
    beq construct_spell_entity_visual_resource_c133ef
    .a16
    lda #$C81E
    jsr copy_spell_entity_sprite_record_words
construct_spell_entity_visual_resource_c133ef:
    ply
    dec $09
    bne construct_spell_entity_visual_resource_c133dd
construct_spell_entity_visual_resource_c133f4:
    ldy $03
    ldx $05
    lda f:$DCF806,X
    .a16
    and #$00FF
    sta a:$0010,Y
    lda f:$DCF807,X
    .a16
    and #$00FF
    sta a:$0012,Y
    sta a:$0014,Y
    lda f:$DCF80A,X
    .a16
    and #$00FF
    sta a:$001E,Y
    sta a:$0020,Y
    lda f:$DCF808,X
    sta a:$001A,Y
    lda $01
    sta a:$0018,Y
    .a16
    and #$000F
    asl
    clc
    adc a:$0000,Y
    tay
    lda f:$DCF808,X
    tyx
    tay
    .a16
    lda #$D104
    jsr copy_spell_entity_sprite_record_words
    ldy $03
    ldx a:$0000,Y
    jsr queue_spell_entity_sprite_slot_write
    ldx $03
    ldy $0B
    beq construct_spell_entity_visual_resource_c13451
    .a16
    lda #$0002
    sta a:$0026,X
construct_spell_entity_visual_resource_c13451:
    tsc
    clc
    .a16
    adc #$000E
    tcs
    plp
    pld
    rts
