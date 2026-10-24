; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-music-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16

copy_scene_palette_templates_and_refresh_special_palette_rows = $F8E9

.segment "CODE"
.org $F8E5
prepare_scene_palette_templates_long:
    jsr copy_scene_palette_templates_and_refresh_special_palette_rows
    rtl
