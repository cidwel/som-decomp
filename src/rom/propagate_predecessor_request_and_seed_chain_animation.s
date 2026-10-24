; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $79E3
propagate_predecessor_request_and_seed_chain_animation:
    ldx $87
    ldy a:$00B0,X
    lda a:$0082,X
    sta a:$0014,X
    lda a:$0080,X
    sta a:$0082,X
    lda a:$0082,Y
    sta a:$0080,X
    lda a:$0014,X
    .a16
    cmp #$FFFF
    bne propagate_predecessor_request_and_seed_chain_animation_c27a08
    .a16
    lda #$013B
    jsr select_boss_animation_and_reset_frame_cursor
propagate_predecessor_request_and_seed_chain_animation_c27a08:
    rts
