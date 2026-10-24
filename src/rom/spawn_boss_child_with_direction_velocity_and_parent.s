; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-capture.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $6BAE
spawn_boss_child_with_direction_velocity_and_parent:
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$00A9,X
    sta $9D
    stx $9F
    lda a:$00AB,X
    asl
    asl
    tax
    lda f:$DCE440,X
    sta $99
    lda f:$DCE442,X
    sta $9B
    .i16
    ldy #$A901
    .i16
    ldx #$6D6F
    jsr allocate_boss_object_pool_slot
    bcs spawn_boss_child_with_direction_velocity_and_parent_c26bfe
    lda $95
    sta a:$002B,X
    lda $97
    sec
    .a16
    sbc #$0020
    sta a:$0032,X
    lda $99
    sta a:$003C,X
    lda $9B
    sta a:$0040,X
    lda $9D
    sta a:$00A9,X
    lda $9F
    sta a:$00B0,X
spawn_boss_child_with_direction_velocity_and_parent_c26bfe:
    rts
