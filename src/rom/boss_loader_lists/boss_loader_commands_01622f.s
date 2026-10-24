.setcpu "65816"
.segment "CODE"
.org $622F
.include "boss_loader_command_macros.inc"
boss_loader_pc_c1622f:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16234:
    boss_loader_create_descriptor_object $0006
boss_loader_pc_c16237:
    boss_loader_allocate_object $2000, $D3F9
boss_loader_pc_c1623c:
    boss_loader_allocate_object $2000, $415D
boss_loader_pc_c16241:
    boss_loader_load_indirect_vram_resource $0003
boss_loader_pc_c16244:
    boss_loader_load_indirect_vram_resource $0004
boss_loader_pc_c16247:
    boss_loader_end
