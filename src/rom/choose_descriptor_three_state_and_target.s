; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_to_low_byte_target = $091D
draw_boss_frame_random_number = $300B
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $62C2
choose_descriptor_three_state_and_target:
    lda a:$007E,X
    beq choose_descriptor_three_state_and_target_c262d2
    stz a:$007E,X
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    beq choose_descriptor_three_state_and_target_c262da
choose_descriptor_three_state_and_target_c262d2:
    .a16
    lda #$0004
    jsr draw_boss_frame_random_number
    bne choose_descriptor_three_state_and_target_c262e9
choose_descriptor_three_state_and_target_c262da:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    ldx $87
    sta a:$00A9,X
    .a16
    lda #$DFC2
    rts
choose_descriptor_three_state_and_target_c262e9:
    ldx $87
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    sta a:$00AB,X
    .a16
    bit #$0001
    beq choose_descriptor_three_state_and_target_c26302
    .a16
    lda #$DFBC
    rts
choose_descriptor_three_state_and_target_c26302:
    .a16
    bit #$0002
    bne choose_descriptor_three_state_and_target_c2630b
    .a16
    lda #$DFBE
    rts
choose_descriptor_three_state_and_target_c2630b:
    .a16
    lda #$DFC0
    rts
