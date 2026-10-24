; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

select_scene_color_targets_from_cursor_and_fade_flags = $9D78

.segment "CODE"
.org $9D67
copy_selected_scene_color_targets_to_current_values:
    jsr select_scene_color_targets_from_cursor_and_fade_flags
    sep #$30
    .i8
    ldx #$05
copy_selected_scene_color_targets_to_current_values_c09d6e:
    lda a:$0A4C,X
    sta a:$0A46,X
    dex
    bpl copy_selected_scene_color_targets_to_current_values_c09d6e
    rts
