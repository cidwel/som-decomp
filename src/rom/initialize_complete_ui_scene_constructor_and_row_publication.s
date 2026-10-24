; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

compute_scene_attribute_scroll_weights_with_multiplier = $8566
consume_pending_scene_target_initialization = $8266
initialize_scene_centers_color_math_and_hdma = $8366
initialize_scene_object_cursor_control_words = $9CEF
initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes = $9996
initialize_scene_window_curve_and_channel_seven_hdma = $9550
install_scene_frame_jump_vectors = $8350
request_map_entry_fade = $8B30
routine_01f828 = $1F828
routine_01fdb8 = $1FDB8
routine_02a914 = $2A914
routine_02af7d = $2AF7D

.segment "CODE"
.org $82C4
initialize_complete_ui_scene_constructor_and_row_publication:
    jsl f:routine_01fdb8
    sep #$10
    rep #$20
    .i8
    ldx #$CE
    .a16
    lda #$0000
initialize_complete_ui_scene_constructor_and_row_publication_c082d1:
    sta $00,X
    dex
    dex
    bne initialize_complete_ui_scene_constructor_and_row_publication_c082d1
    .a16
    lda #$2000
    sta $C2
    .i8
    ldx #$44
    stx a:$210B
    .i8
    ldx #$51
    stx a:$2107
    .i8
    ldx #$59
    stx a:$2108
    .a16
    lda #$8024
    sta $5C
    .i8
    ldx #$FF
    stx $5E
    lda $F5
    .a16
    ora #$0001
    sta $F5
    .a16
    lda #$2C00
    sta $A4
    .a16
    lda #$F000
    sta $A2
    .a16
    lda #$EC00
    sta $92
    .a16
    lda #$2800
    sta $94
    .i8
    ldx #$84
    stx a:$4207
    .i8
    ldx #$00
    stx a:$4208
    .i8
    ldx #$60
    stx a:$4209
    .i8
    ldx #$00
    stx a:$420A
    jsr consume_pending_scene_target_initialization
    jsr compute_scene_attribute_scroll_weights_with_multiplier
    jsr initialize_scene_centers_color_math_and_hdma
    jsl f:routine_02af7d
    jsl f:routine_01f828
    jsr initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes
    jsr initialize_scene_object_cursor_control_words
    jsr install_scene_frame_jump_vectors
    jsr initialize_scene_window_curve_and_channel_seven_hdma
    rep #$10
    .i16
    ldx #$0F00
    .i16
    ldy #$0401
    jsr request_map_entry_fade
    jsl f:routine_02a914
    rts
