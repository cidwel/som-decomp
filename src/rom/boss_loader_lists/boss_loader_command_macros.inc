; Typed boss-loader commands; docs/boss-loader-command-numeric.md.
.macro boss_loader_load_palette palette_id, row_id
    .byte $01
    .word palette_id, row_id
.endmacro
.macro boss_loader_allocate_object flags, definition_pointer
    .byte $04
    .word flags, definition_pointer
.endmacro
.macro boss_loader_load_ram_resource_11 resource_id
    .byte $11
    .word resource_id
.endmacro
.macro boss_loader_load_direct_vram_resource resource_id
    .byte $12
    .word resource_id
.endmacro
.macro boss_loader_write_word destination, value
    .byte $13
    .word destination, value
.endmacro
.macro boss_loader_allocate_and_prepare_object flags, definition_pointer
    .byte $16
    .word flags, definition_pointer
.endmacro
.macro boss_loader_initialize_graphics_pattern
    .byte $17
.endmacro
.macro boss_loader_reset_secondary_object_buffers
    .byte $18
.endmacro
.macro boss_loader_create_descriptor_object descriptor_index
    .byte $19
    .word descriptor_index
.endmacro
.macro boss_loader_fill_graphics_buffers
    .byte $1B
.endmacro
.macro boss_loader_call_native_callback callback_pointer
    .byte $1C
    .word callback_pointer
.endmacro
.macro boss_loader_load_indirect_vram_resource resource_id
    .byte $1D
    .word resource_id
.endmacro
.macro boss_loader_load_indirect_vram_high_resource resource_id
    .byte $1E
    .word resource_id
.endmacro
.macro boss_loader_end
    .byte $FF
.endmacro
