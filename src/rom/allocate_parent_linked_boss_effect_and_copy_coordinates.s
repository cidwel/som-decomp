; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $3385
allocate_parent_linked_boss_effect_and_copy_coordinates:
    sta a:$00A7,X
    sta a:$001E,X
    sta $95
    lda a:$002B,X
    sta $97
    lda a:$0032,X
    sta $99
    lda a:$0098,X
    .a16
    and #$0007
    .a16
    ora #$2800
    tay
    .i16
    ldx #$311D
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    lda $95
    sta a:$00A7,X
    lda $97
    sta a:$002B,X
    lda $99
    sta a:$0032,X
    lda $87
    rts
