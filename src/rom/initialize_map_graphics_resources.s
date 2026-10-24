; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_map_fixed_graphics = $F69B
prepare_map_resource_palette = $F62D
upload_map_graphics_descriptor_list = $F413
upload_map_mirrored_pattern_tiles = $F702
upload_map_scroll_graphics_templates = $F5CE

.segment "CODE"
.org $F403
initialize_map_graphics_resources:
    jsr upload_map_scroll_graphics_templates
    jsr prepare_map_resource_palette
    jsr initialize_map_fixed_graphics
    jsr upload_map_mirrored_pattern_tiles
    jsr upload_map_graphics_descriptor_list
    rtl
