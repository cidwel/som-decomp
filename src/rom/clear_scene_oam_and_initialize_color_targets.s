; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

copy_selected_scene_color_targets_to_current_values = $9D67
publish_scene_oam_buffer_through_dma_seven = $9A91

.segment "CODE"
.org $9CAB
clear_scene_oam_and_initialize_color_targets:
    rep #$30
    .i16
    ldx #$0000
    .a16
    lda #$E0FF
clear_scene_oam_and_initialize_color_targets_c09cb3:
    sta a:$0800,X
    inx
    inx
    inx
    inx
    .i16
    cpx #$0200
    bcc clear_scene_oam_and_initialize_color_targets_c09cb3
    sep #$30
    .i8
    ldx #$3F
    .a8
    lda #$00
clear_scene_oam_and_initialize_color_targets_c09cc5:
    sta a:$0A00,X
    dex
    bpl clear_scene_oam_and_initialize_color_targets_c09cc5
    jsr publish_scene_oam_buffer_through_dma_seven
    sep #$20
    .a8
    lda #$00
    sta $7C
    sta $7D
    jmp copy_selected_scene_color_targets_to_current_values
