; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
boss_attack_row_public_jump = $C0006C

.segment "CODE"
.org $6501
initialize_descriptor_nine_height_child_and_attack_row:
    .a16
    lda #$003F
    sta a:$0066,X
    .i16
    ldy #$B901
    .i16
    ldx #$6610
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    stz a:$007E,X
    .a16
    lda #$0064
    jsl f:boss_attack_row_public_jump
    rts
