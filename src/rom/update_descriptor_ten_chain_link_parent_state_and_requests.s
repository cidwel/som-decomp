; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

consume_primary_boss_request_into_chain_delay_queue = $79B8
orient_descriptor_ten_chain_link_from_parent_quadrant = $78AA
propagate_predecessor_request_and_seed_chain_animation = $79E3

.segment "CODE"
.org $7831
update_descriptor_ten_chain_link_parent_state_and_requests:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0007
    bcs update_descriptor_ten_chain_link_parent_state_and_requests_c27855
    jsr orient_descriptor_ten_chain_link_from_parent_quadrant
    ldx $87
    lda a:$00B0,X
    .a16
    cmp #$E600
    bne update_descriptor_ten_chain_link_parent_state_and_requests_c27850
    jsr consume_primary_boss_request_into_chain_delay_queue
    bra update_descriptor_ten_chain_link_parent_state_and_requests_c27853
update_descriptor_ten_chain_link_parent_state_and_requests_c27850:
    jsr propagate_predecessor_request_and_seed_chain_animation
update_descriptor_ten_chain_link_parent_state_and_requests_c27853:
    clc
    rts
update_descriptor_ten_chain_link_parent_state_and_requests_c27855:
    .a16
    lda #$0006
    sta a:$0094,X
    clc
    rts
