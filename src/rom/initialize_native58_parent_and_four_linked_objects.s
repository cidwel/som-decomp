; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
select_boss_animation_and_reset_frame_cursor = $1394
select_nearest_active_living_party_actor = $3224
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $7B0F
initialize_native58_parent_and_four_linked_objects:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    inc a:$0094,X
    .a16
    lda #$0121
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B0,X
    stz a:$00B2,X
    stz a:$00B4,X
    stz a:$00B6,X
    stz a:$00B8,X
    stz a:$003C,X
    stz a:$0040,X
    .a16
    lda #$0006
    sta a:$001E,X
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    lda a:$0042,X
    sta $99
    .i16
    ldy #$1801
    .i16
    ldx #$7EC3
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    lda $99
    sta a:$0042,X
    .a16
    lda #$0001
    sta a:$0182,X
    stx $95
    .i16
    ldy #$1801
    .i16
    ldx #$8009
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    lda $99
    sta a:$0042,X
    .a16
    lda #$0001
    sta a:$0182,X
    stx $97
    .i16
    ldy #$2A29
    .i16
    ldx #$8374
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    lda $99
    sta a:$0042,X
    lda $87
    sta a:$00B2,X
    .i16
    ldy #$2A29
    .i16
    ldx #$83D8
    jsr allocate_boss_object_pool_slot
    lda $97
    sta a:$00B0,X
    lda $99
    sta a:$0042,X
    lda $87
    sta a:$00B2,X
