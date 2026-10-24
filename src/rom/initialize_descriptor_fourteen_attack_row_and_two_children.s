; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
boss_attack_row_public_jump = $C0006C
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $5150
initialize_descriptor_fourteen_attack_row_and_two_children:
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$002A
    sta a:$00A5,X
    .a16
    lda #$0011
    sta a:$001E,X
    .a16
    lda #$005F
    jsl f:boss_attack_row_public_jump
    ldx $87
    stx $95
    .i16
    ldx #$5354
    .i16
    ldy #$3801
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0000
    sta a:$00B2,X
    .i16
    ldx #$5354
    .i16
    ldy #$3801
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0001
    sta a:$00B2,X
    rts
