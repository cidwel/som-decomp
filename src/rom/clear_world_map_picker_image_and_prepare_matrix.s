; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_world_map_picker_scaled_matrix_coefficients = $A9E1

.segment "CODE"
.org $A615
clear_world_map_picker_image_and_prepare_matrix:
    sep #$30
    inc $1E
    sep #$30
    .a8
    lda #$01
    stz a:$2181
    stz a:$2182
    sta a:$2183
    .i8
    ldx #$40
    .i8
    ldy #$00
    .a8
    lda #$C0
clear_world_map_picker_image_and_prepare_matrix_c0a62c:
    sta a:$2180
    iny
    bne clear_world_map_picker_image_and_prepare_matrix_c0a62c
    dex
    bne clear_world_map_picker_image_and_prepare_matrix_c0a62c
    jmp prepare_world_map_picker_scaled_matrix_coefficients
