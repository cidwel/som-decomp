.setcpu "65816"
.segment "CODE"
.org $6497
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16497:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c16498:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c1649d:
    boss_loader_create_descriptor_object $000B
boss_loader_pc_c164a0:
    boss_loader_load_indirect_vram_resource $0001
boss_loader_pc_c164a3:
    boss_loader_load_indirect_vram_resource $0002
boss_loader_pc_c164a6:
    boss_loader_end
