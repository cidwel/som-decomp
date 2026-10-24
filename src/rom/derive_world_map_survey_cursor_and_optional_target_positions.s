; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A8C8
derive_world_map_survey_cursor_and_optional_target_positions:
    sep #$20
    lda $15
    beq derive_world_map_survey_cursor_and_optional_target_positions_c2a8d0
    .a8
    lda #$20
derive_world_map_survey_cursor_and_optional_target_positions_c2a8d0:
    sta $02
    bit $E3
    bvc derive_world_map_survey_cursor_and_optional_target_positions_c2a8f7
    rep #$20
    lda a:$0128
    lsr
    lsr
    lsr
    lsr
    sta $00
    lda a:$012A
    lsr
    lsr
    lsr
    lsr
    sep #$20
    sec
    sbc $02
    .a8
    sbc #$08
    sta a:$0811
    lda $00
    sta a:$0810
derive_world_map_survey_cursor_and_optional_target_positions_c2a8f7:
    lda $09
    lsr
    lda $08
    ror
    sec
    .a8
    sbc #$10
    sta $00
    lda $0B
    lsr
    lda $0A
    ror
    sec
    .a8
    sbc #$10
    sbc $02
    sta $01
    rep #$20
    lda $00
    rts
