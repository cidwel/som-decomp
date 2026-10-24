; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

clear_scene_oam_and_initialize_color_targets = $9CAB

.segment "CODE"
.org $9CEF
initialize_scene_object_cursor_control_words:
    jsr clear_scene_oam_and_initialize_color_targets
    sep #$10
    rep #$20
    .i8
    ldx #$00
initialize_scene_object_cursor_control_words_c09cf8:
    lda a:$9CE9,X
    sta a:$0A40,X
    inx
    inx
    .i8
    cpx #$06
    bcc initialize_scene_object_cursor_control_words_c09cf8
    .a16
    lda #$0000
    sta $7A
    rts
