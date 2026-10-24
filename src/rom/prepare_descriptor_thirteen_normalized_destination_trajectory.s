; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16

derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed = $6877
dispatch_descriptor_thirteen_variant_destination_selection = $67E5
normalize_boss_displacement_to_signed_fixed_point = $2F61

.segment "CODE"
.org $67D1
prepare_descriptor_thirteen_normalized_destination_trajectory:
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $99
    jsr dispatch_descriptor_thirteen_variant_destination_selection
    jsr normalize_boss_displacement_to_signed_fixed_point
    jsr derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed
    rts
