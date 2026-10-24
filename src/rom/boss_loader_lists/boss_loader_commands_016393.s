.setcpu "65816"
.segment "CODE"
.org $6393
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16393:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16398:
    boss_loader_create_descriptor_object $000D
boss_loader_pc_c1639b:
    boss_loader_load_indirect_vram_resource $0012
boss_loader_pc_c1639e:
    boss_loader_end
