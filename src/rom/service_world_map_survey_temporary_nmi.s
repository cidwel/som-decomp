; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

converge_world_map_survey_brightness_to_requested_level = $AC49

.segment "CODE"
.org $AC26
service_world_map_survey_temporary_nmi:
    sep #$20
    pha
    phb
    .a8
    lda #$00
    pha
    plb
    lda a:$4210
    inc a:$00F4
    lda a:$000E
    and a:$000F
    beq service_world_map_survey_temporary_nmi_c0ac41
    bmi service_world_map_survey_temporary_nmi_c0ac41
    jsr converge_world_map_survey_brightness_to_requested_level
service_world_map_survey_temporary_nmi_c0ac41:
    .a8
    lda #$00
    sta a:$000E
    plb
    pla
    rti
