; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

choose_shared_or_party_character_graphics_upload = $F8A7
copy_scene_palette_templates_and_refresh_special_palette_rows = $F8E9
expand_packed_scene_tile_attributes_and_snapshot_vram = $F83C
initialize_scene_vram_and_apply_fixed_attribute_fill_records = $F96A
publish_current_palette_buffer_through_dma_channel_seven = $F944
routine_02b75e = $2B75E

.segment "CODE"
.org $F828
construct_complete_scene_graphics_palette_and_vram:
    jsr expand_packed_scene_tile_attributes_and_snapshot_vram
    jsr choose_shared_or_party_character_graphics_upload
    jsr copy_scene_palette_templates_and_refresh_special_palette_rows
    jsl f:routine_02b75e
    jsr publish_current_palette_buffer_through_dma_channel_seven
    jsr initialize_scene_vram_and_apply_fixed_attribute_fill_records
    rtl
