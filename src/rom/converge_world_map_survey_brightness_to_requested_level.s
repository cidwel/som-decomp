; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AC49
converge_world_map_survey_brightness_to_requested_level:
    lda a:$000C
    cmp a:$000D
    beq converge_world_map_survey_brightness_to_requested_level_c0ac5a
    bcs converge_world_map_survey_brightness_to_requested_level_c0ac56
    inc
    bra converge_world_map_survey_brightness_to_requested_level_c0ac57
converge_world_map_survey_brightness_to_requested_level_c0ac56:
    dec
converge_world_map_survey_brightness_to_requested_level_c0ac57:
    sta a:$000C
converge_world_map_survey_brightness_to_requested_level_c0ac5a:
    sta a:$2100
    rts
