; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $66A0
initialize_descriptor_thirteen_height_and_two_linked_children:
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0080
    sta a:$0066,X
    stz a:$007E,X
    stx $95
    .i16
    ldy #$3821
    .i16
    ldx #$6A11
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    stz a:$00B2,X
    .i16
    ldy #$3821
    .i16
    ldx #$6A11
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$00B0,X
    .a16
    lda #$0001
    sta a:$00B2,X
    lda $C7
    sta a:$0362
    rts
