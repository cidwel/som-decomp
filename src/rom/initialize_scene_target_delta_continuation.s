; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

compute_wrapped_scene_target_deltas_and_direction_flags = $8E9E

.segment "CODE"
.org $8E92
initialize_scene_target_delta_continuation:
    jsr compute_wrapped_scene_target_deltas_and_direction_flags
    lda $00
    sta $84
    lda $02
    sta $88
    rts
