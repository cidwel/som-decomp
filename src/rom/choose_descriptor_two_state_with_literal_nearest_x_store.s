; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_to_low_byte_target = $091D
request_descriptor_two_half_hp_phase_and_height = $3FB5
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $3F93
choose_descriptor_two_state_with_literal_nearest_x_store:
    jsr select_nearest_active_living_party_actor
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    sta a:$00AB,X
    lda a:$007E,X
    bne choose_descriptor_two_state_with_literal_nearest_x_store_c23fa7
    jsr request_descriptor_two_half_hp_phase_and_height
choose_descriptor_two_state_with_literal_nearest_x_store_c23fa7:
    lda a:$00AB,X
    asl
    clc
    adc a:$007E,X
    tax
    lda f:$DCE068,X
    rts
