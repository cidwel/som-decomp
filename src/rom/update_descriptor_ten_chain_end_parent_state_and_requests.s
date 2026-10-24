; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant = $78DC
propagate_predecessor_request_and_seed_chain_animation = $79E3
propagate_predecessor_request_without_end_animation_reseed = $7A09

.segment "CODE"
.org $785D
update_descriptor_ten_chain_end_parent_state_and_requests:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0007
    bcs update_descriptor_ten_chain_end_parent_state_and_requests_c2787e
    jsr orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant
    ldx $87
    lda a:$0042,X
    bne update_descriptor_ten_chain_end_parent_state_and_requests_c27879
    jsr propagate_predecessor_request_and_seed_chain_animation
    bra update_descriptor_ten_chain_end_parent_state_and_requests_c2787c
update_descriptor_ten_chain_end_parent_state_and_requests_c27879:
    jsr propagate_predecessor_request_without_end_animation_reseed
update_descriptor_ten_chain_end_parent_state_and_requests_c2787c:
    clc
    rts
update_descriptor_ten_chain_end_parent_state_and_requests_c2787e:
    .a16
    lda #$0006
    sta a:$0094,X
    clc
    rts
