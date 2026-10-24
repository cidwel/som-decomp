.setcpu "65816"
.segment "CODE"
.org $6382
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16382:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16387:
    boss_loader_create_descriptor_object $000D
boss_loader_pc_c1638a:
    boss_loader_load_indirect_vram_resource $0012
boss_loader_pc_c1638d:
    boss_loader_end
