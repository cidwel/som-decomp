; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

derive_world_map_survey_cursor_and_optional_target_positions = $A8C8

.segment "CODE"
.org $A852
animate_and_upload_world_map_survey_cursor_objects:
    rep #$20
    sep #$10
    lda $F4
    .a16
    bit #$0008
    bne animate_and_upload_world_map_survey_cursor_objects_c2a862
    .a16
    lda #$3FE1
    bra animate_and_upload_world_map_survey_cursor_objects_c2a865
animate_and_upload_world_map_survey_cursor_objects_c2a862:
    .a16
    lda #$3FE2
animate_and_upload_world_map_survey_cursor_objects_c2a865:
    sta a:$0812
    lda $F4
    .a16
    bit #$0010
    beq animate_and_upload_world_map_survey_cursor_objects_c2a87d
    .a16
    lda #$E0FF
    sta a:$0800
    sta a:$0804
    sta a:$0808
    bra animate_and_upload_world_map_survey_cursor_objects_c2a8a2
animate_and_upload_world_map_survey_cursor_objects_c2a87d:
    jsr derive_world_map_survey_cursor_and_optional_target_positions
    sta a:$0800
    sep #$20
    pha
    clc
    .a8
    adc #$10
    rep #$20
    sta a:$0804
    sep #$20
    pla
    xba
    clc
    .a8
    adc #$10
    xba
    rep #$20
    sta a:$0808
    sep #$20
    clc
    .a8
    adc #$10
    rep #$20
animate_and_upload_world_map_survey_cursor_objects_c2a8a2:
    sta a:$080C
    .a16
    lda #$0000
    sta a:$2102
    .a16
    lda #$0800
    sta a:$4372
    .a16
    lda #$0400
    sta a:$4370
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0014
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    rtl
