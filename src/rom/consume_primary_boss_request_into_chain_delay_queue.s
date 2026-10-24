; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $79B8
consume_primary_boss_request_into_chain_delay_queue:
    ldx $87
    ldy a:$00B0,X
    lda a:$0082,X
    sta a:$0014,X
    lda a:$0080,X
    sta a:$0082,X
    lda a:$00B4,Y
    sta a:$0080,X
    lda $C5
    sta a:$00B4,Y
    lda a:$0014,X
    .a16
    cmp #$FFFF
    bne consume_primary_boss_request_into_chain_delay_queue_c279e2
    .a16
    lda #$013B
    jsr select_boss_animation_and_reset_frame_cursor
consume_primary_boss_request_into_chain_delay_queue_c279e2:
    rts
