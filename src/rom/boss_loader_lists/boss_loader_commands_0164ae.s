.setcpu "65816"
.segment "CODE"
.org $64AE
.include "boss_loader_command_macros.inc"
boss_loader_pc_c164ae:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c164af:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c164b4:
    boss_loader_create_descriptor_object $000B
boss_loader_pc_c164b7:
    boss_loader_load_indirect_vram_resource $0001
boss_loader_pc_c164ba:
    boss_loader_load_indirect_vram_resource $0002
boss_loader_pc_c164bd:
    boss_loader_end
