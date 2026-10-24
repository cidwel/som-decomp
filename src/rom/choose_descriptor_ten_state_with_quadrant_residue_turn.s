; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_to_low_byte_target = $091D
draw_boss_frame_random_number = $300B
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $7605
choose_descriptor_ten_state_with_quadrant_residue_turn:
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    bne choose_descriptor_ten_state_with_quadrant_residue_turn_c27619
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE56F,X
    rts
choose_descriptor_ten_state_with_quadrant_residue_turn_c27619:
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    lda $6A
    sta $95
    ldx $87
    sec
    sbc a:$00AB,X
    bpl choose_descriptor_ten_state_with_quadrant_residue_turn_c27633
    eor $C7
    inc
choose_descriptor_ten_state_with_quadrant_residue_turn_c27633:
    .a16
    cmp #$0002
    bne choose_descriptor_ten_state_with_quadrant_residue_turn_c27652
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bne choose_descriptor_ten_state_with_quadrant_residue_turn_c2764a
    lda $95
    inc
    .a16
    and #$0003
    sta $95
    bra choose_descriptor_ten_state_with_quadrant_residue_turn_c27652
choose_descriptor_ten_state_with_quadrant_residue_turn_c2764a:
    lda $95
    dec
    .a16
    and #$0003
    sta $95
choose_descriptor_ten_state_with_quadrant_residue_turn_c27652:
    lda $95
    ldx $87
    sta a:$00AB,X
    asl
    tax
    lda f:$DCE567,X
    clc
    rts
