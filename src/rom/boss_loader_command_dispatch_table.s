; Thirty-one command handler offsets in bank C2; see docs/maps.md.
.setcpu "65816"
boss_loader_allocate_and_prepare_object = $227E
boss_loader_allocate_object_operands = $222B
boss_loader_call_native_callback = $2459
boss_loader_create_descriptor_object = $23DA
boss_loader_direct_vram_high_operands = $23E7
boss_loader_direct_vram_low_high_operands = $2252
boss_loader_indirect_vram_high_operands = $246D
boss_loader_indirect_vram_low_high_operands = $2464
boss_loader_load_palette_operands = $2218
boss_loader_ram_resource_operands = $2249
boss_loader_reserved_02_03 = $222A
boss_loader_reserved_05_06 = $223C
boss_loader_reserved_parameter_14 = $226C
boss_loader_reserved_parameter_15 = $2275
boss_loader_reset_object_pool = $223D
boss_loader_write_word = $225B
fill_boss_graphics_buffers_through_dma = $23F0
initialize_boss_graphics_pattern = $234B
reset_boss_secondary_object_buffers = $238A
unmodelled_boss_sound_command_operands = $2240

.segment "CODE"
.org $21DA
boss_loader_command_dispatch_table:
    .word boss_loader_load_palette_operands ; opcode $00
    .word boss_loader_load_palette_operands ; opcode $01
    .word boss_loader_reserved_02_03 ; opcode $02
    .word boss_loader_reserved_02_03 ; opcode $03
    .word boss_loader_allocate_object_operands ; opcode $04
    .word boss_loader_reserved_05_06 ; opcode $05
    .word boss_loader_reserved_05_06 ; opcode $06
    .word boss_loader_reset_object_pool ; opcode $07
    .word unmodelled_boss_sound_command_operands ; opcode $08
    .word boss_loader_ram_resource_operands ; opcode $09
    .word boss_loader_ram_resource_operands ; opcode $0A
    .word boss_loader_ram_resource_operands ; opcode $0B
    .word boss_loader_ram_resource_operands ; opcode $0C
    .word boss_loader_ram_resource_operands ; opcode $0D
    .word boss_loader_ram_resource_operands ; opcode $0E
    .word boss_loader_ram_resource_operands ; opcode $0F
    .word boss_loader_ram_resource_operands ; opcode $10
    .word boss_loader_ram_resource_operands ; opcode $11
    .word boss_loader_direct_vram_low_high_operands ; opcode $12
    .word boss_loader_write_word ; opcode $13
    .word boss_loader_reserved_parameter_14 ; opcode $14
    .word boss_loader_reserved_parameter_15 ; opcode $15
    .word boss_loader_allocate_and_prepare_object ; opcode $16
    .word initialize_boss_graphics_pattern ; opcode $17
    .word reset_boss_secondary_object_buffers ; opcode $18
    .word boss_loader_create_descriptor_object ; opcode $19
    .word boss_loader_direct_vram_high_operands ; opcode $1A
    .word fill_boss_graphics_buffers_through_dma ; opcode $1B
    .word boss_loader_call_native_callback ; opcode $1C
    .word boss_loader_indirect_vram_low_high_operands ; opcode $1D
    .word boss_loader_indirect_vram_high_operands ; opcode $1E
