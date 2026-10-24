; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
change_actor_identity_public_jump = $C0003F
select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $7ED5
initialize_left_child_identity_and_linked_grandchild:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$3000
    sta a:$0092,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0066,X
    inc a:$0094,X
    sep #$20
    stz a:$0046,X
    stz a:$0047,X
    stz a:$0074,X
    .a8
    lda #$01
    sta a:$0010,X
    rep #$20
    lda a:$00B0,X
    sta $95
    lda a:$0042,X
    sta $97
    .i16
    ldy #$3901
    .i16
    ldx #$8138
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    lda $95
    sta a:$00B2,X
    lda $97
    sta a:$0042,X
    ldx $87
    ldy a:$00B0,X
    lda a:$0042,Y
    tax
    lda f:$C28136,X
    .a16
    and #$00FF
    ldx $87
    jsl f:change_actor_identity_public_jump
