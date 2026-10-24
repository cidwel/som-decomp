; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $74F9
initialize_descriptor_ten_linked_child_allocation_chain:
    jsr set_boss_animation_bank_low_byte_c7
    lda a:$002B,X
    sta a:$0358
    lda a:$0032,X
    sta a:$035C
    .a16
    lda #$0002
    sta a:$001E,X
    sta a:$000B,X
    stz a:$0066,X
    .i16
    ldy #$1801
    .i16
    ldx #$77A7
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    .a16
    lda #$0000
    sta a:$00B2,X
    .a16
    lda #$0001
    sta a:$00B4,X
    stx $95
    .i16
    ldy #$1801
    .i16
    ldx #$77A7
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$00CC
    sta a:$00B2,X
    .a16
    lda #$0002
    sta a:$00B4,X
    stx $95
    .i16
    ldy #$3801
    .i16
    ldx #$77A7
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0198
    sta a:$00B2,X
    .a16
    lda #$0004
    sta a:$00B4,X
    stx $95
    .i16
    ldy #$3801
    .i16
    ldx #$77A7
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0264
    sta a:$00B2,X
    .a16
    lda #$0008
    sta a:$00B4,X
    stx $95
    .i16
    ldy #$3801
    .i16
    ldx #$77A7
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0330
    sta a:$00B2,X
    .a16
    lda #$0008
    sta a:$00B4,X
    stx $95
    ldx $87
    lda a:$0042,X
    bne initialize_descriptor_ten_linked_child_allocation_chain_c275c3
    .i16
    ldy #$3801
    .i16
    ldx #$77A7
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$03FC
    sta a:$00B2,X
    .a16
    lda #$0008
    sta a:$00B4,X
    stx $95
initialize_descriptor_ten_linked_child_allocation_chain_c275c3:
    .i16
    ldy #$3801
    .i16
    ldx #$77BF
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$04C8
    sta a:$00B2,X
    .a16
    lda #$0008
    sta a:$00B4,X
    stz a:$0042,X
    stx $95
    .i16
    ldy #$3801
    .i16
    ldx #$77BF
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0594
    sta a:$00B2,X
    .a16
    lda #$0008
    sta a:$00B4,X
    .a16
    lda #$0001
    sta a:$0042,X
    stx $95
    rts
