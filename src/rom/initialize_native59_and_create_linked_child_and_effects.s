; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
dispatch_native59_variant_hp_scaling = $876C
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8471
initialize_native59_and_create_linked_child_and_effects:
    ldx $87
    sep #$20
    .a8
    lda #$FF
    sta a:$000A,X
    rep #$20
    inc a:$0094,X
    .a16
    lda #$010B
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0008
    sta a:$0070,X
    .a16
    lda #$0008
    sta a:$001E,X
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$00AD,X
    stz a:$00B0,X
    stz a:$00B6,X
    .a16
    lda #$FFF4
    sta a:$0062,X
    eor $C7
    inc
    sta a:$0045,X
    lda $C7
    sta a:$0362
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sec
    .a16
    sbc #$0010
    sta $97
    lda a:$0042,X
    sta $99
    txa
    sta $9B
    .i16
    ldx #$8883
    .i16
    ldy #$290D
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    lda $99
    sta a:$0042,X
    lda $9B
    sta a:$00B6,X
    txa
    ldx $87
    sta a:$00B4,X
    jsr dispatch_native59_variant_hp_scaling
    .i16
    ldx #$8A91
    .i16
    ldy #$B821
    jsr allocate_boss_object_pool_slot
    .i16
    ldx #$3D34
    .i16
    ldy #$2A20
    jsr allocate_boss_object_pool_slot
