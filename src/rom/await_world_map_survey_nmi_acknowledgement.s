; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AFA3
await_world_map_survey_nmi_acknowledgement:
    sep #$20
    .a8
    lda #$01
    sta $0E
await_world_map_survey_nmi_acknowledgement_c0afa9:
    bit $0E
    bne await_world_map_survey_nmi_acknowledgement_c0afa9
    rts
