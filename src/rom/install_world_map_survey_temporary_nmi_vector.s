; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AC14
install_world_map_survey_temporary_nmi_vector:
    sep #$30
    .i8
    ldx #$03
install_world_map_survey_temporary_nmi_vector_c0ac18:
    lda a:$AC22,X
    sta a:$0100,X
    dex
    bpl install_world_map_survey_temporary_nmi_vector_c0ac18
    rts
