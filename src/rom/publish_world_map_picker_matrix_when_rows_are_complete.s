; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A691
publish_world_map_picker_matrix_when_rows_are_complete:
    sep #$30
    lda $0E
    beq publish_world_map_picker_matrix_when_rows_are_complete_c0a698
publish_world_map_picker_matrix_when_rows_are_complete_c0a697:
    rts
publish_world_map_picker_matrix_when_rows_are_complete_c0a698:
    lda $0D
    beq publish_world_map_picker_matrix_when_rows_are_complete_c0a697
    lda $1E
    bne publish_world_map_picker_matrix_when_rows_are_complete_c0a697
    stz $1F
    lda $36
    sta a:$211B
    lda $37
    sta a:$211B
    lda $36
    sta a:$211E
    lda $37
    sta a:$211E
    lda $38
    sta a:$211C
    lda $39
    sta a:$211C
    lda $38
    .a8
    eor #$FF
    clc
    .a8
    adc #$01
    sta a:$211D
    lda $39
    .a8
    eor #$FF
    .a8
    adc #$00
    sta a:$211D
    rts
