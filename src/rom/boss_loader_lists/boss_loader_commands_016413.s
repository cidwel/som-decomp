.setcpu "65816"
.segment "CODE"
.org $6413
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16413:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16418:
    boss_loader_create_descriptor_object $000A
boss_loader_pc_c1641b:
    boss_loader_load_indirect_vram_resource $0014
boss_loader_pc_c1641e:
    boss_loader_end
