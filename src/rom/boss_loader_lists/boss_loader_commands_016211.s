.setcpu "65816"
.segment "CODE"
.org $6211
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16211:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16216:
    boss_loader_create_descriptor_object $0002
boss_loader_pc_c16219:
    boss_loader_allocate_object $2000, $41A0
boss_loader_pc_c1621e:
    boss_loader_allocate_object $2000, $415D
boss_loader_pc_c16223:
    boss_loader_load_indirect_vram_resource $0003
boss_loader_pc_c16226:
    boss_loader_load_indirect_vram_resource $0004
boss_loader_pc_c16229:
    boss_loader_end
