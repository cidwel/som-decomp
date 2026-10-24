; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
derive_native54_part_spawn_position_from_variant_and_offset = $4628

.segment "CODE"
.org $4596
create_missing_native54_body_parts_or_mark_variant_zero_limit:
    ldx $87
    lda a:$0042,X
    bne create_missing_native54_body_parts_or_mark_variant_zero_limit_c245ad
    lda a:$00B0,X
    .a16
    cmp #$0002
    bcc create_missing_native54_body_parts_or_mark_variant_zero_limit_c245ad
    .a16
    lda #$0001
    sta a:$00BE,X
    bra create_missing_native54_body_parts_or_mark_variant_zero_limit_c24615
create_missing_native54_body_parts_or_mark_variant_zero_limit_c245ad:
    lda a:$E800
    .a16
    bit #$0001
    bne create_missing_native54_body_parts_or_mark_variant_zero_limit_c245e0
    .a16
    lda #$0000
    jsr derive_native54_part_spawn_position_from_variant_and_offset
    inc a:$00B0,X
    .i16
    ldy #$1811
    .i16
    ldx #$4AFB
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    stz a:$00A9,X
    lda $87
    sta a:$00B0,X
    .a16
    lda #$0001
    sta a:$0182,X
    tax
create_missing_native54_body_parts_or_mark_variant_zero_limit_c245e0:
    lda a:$EA00
    .a16
    bit #$0001
    bne create_missing_native54_body_parts_or_mark_variant_zero_limit_c24615
    .a16
    lda #$0004
    jsr derive_native54_part_spawn_position_from_variant_and_offset
    inc a:$00B0,X
    .i16
    ldy #$1911
    .i16
    ldx #$4AFB
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    .a16
    lda #$0001
    sta a:$00A9,X
    lda $87
    sta a:$00B0,X
    .a16
    lda #$0001
    sta a:$0182,X
create_missing_native54_body_parts_or_mark_variant_zero_limit_c24615:
    ldx $87
    .a16
    lda #$0002
    sta a:$0094,X
    .a16
    lda #$0001
    sta a:$00B2,X
    stz a:$0096,X
    clc
    rts
