; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
select_nearest_active_living_party_actor = $3224
update_descriptor_eleven_facing_phase_or_return_transition_abort = $8BF7

.segment "CODE"
.org $8BCD
choose_descriptor_eleven_distance_variant_state:
    jsr select_nearest_active_living_party_actor
    sta a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0005
    bcc choose_descriptor_eleven_distance_variant_state_c28bdf
    .a16
    lda #$F032
    rts
choose_descriptor_eleven_distance_variant_state_c28bdf:
    .a16
    cmp #$0002
    bcc choose_descriptor_eleven_distance_variant_state_c28be8
    .a16
    lda #$F038
    rts
choose_descriptor_eleven_distance_variant_state_c28be8:
    jsr update_descriptor_eleven_facing_phase_or_return_transition_abort
    bcs choose_descriptor_eleven_distance_variant_state_c28bf6
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE5B5,X
choose_descriptor_eleven_distance_variant_state_c28bf6:
    rts
