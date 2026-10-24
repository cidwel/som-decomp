; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
boss_attack_row_public_jump = $C0006C

.segment "CODE"
.org $86E4
prepare_native59_attack_and_allocate_target_linked_projectile:
    ldx $87
    sep #$20
    stz a:$005A,X
    rep #$20
    lda a:$00B0,X
    tax
    lda f:$C28746,X
    .a16
    and #$00FF
    ldx $87
    jsl f:boss_attack_row_public_jump
    ldx $87
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$00A9,X
    sta $99
    xba
    asl
    clc
    .a16
    adc #$E000
    sta $9B
    .i16
    ldx #$89D1
    .i16
    ldy #$AA01
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    lda $99
    sta a:$00A9,X
    lda $87
    sta a:$00B0,X
    lda $9B
    sta a:$00B2,X
    .a16
    lda #$0001
    sta a:$0070,X
    stz a:$003C,X
    stz a:$0040,X
    rts
