.setcpu "65816"
.segment "CODE"
.org $6422
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16422:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16427:
    boss_loader_create_descriptor_object $000A
boss_loader_pc_c1642a:
    boss_loader_load_indirect_vram_resource $0014
boss_loader_pc_c1642d:
    boss_loader_end
