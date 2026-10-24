.setcpu "65816"
.segment "CODE"
.org $64C5
.include "boss_loader_command_macros.inc"
boss_loader_pc_c164c5:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c164c6:
    boss_loader_write_word $0304, $0002
boss_loader_pc_c164cb:
    boss_loader_create_descriptor_object $000B
boss_loader_pc_c164ce:
    boss_loader_load_indirect_vram_resource $0001
boss_loader_pc_c164d1:
    boss_loader_load_indirect_vram_resource $0002
boss_loader_pc_c164d4:
    boss_loader_end
