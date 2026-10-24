; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-capture.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $6BFF
spawn_boss_child_at_parent_position_and_height:
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$0066,X
    sta $99
    stx $9B
    lda a:$0098,X
    .a16
    and #$0003
    .a16
    ora #$A920
    tay
    .i16
    ldx #$6C9F
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    lda $99
    sta a:$0066,X
    lda $9B
    sta a:$00B0,X
    rts
