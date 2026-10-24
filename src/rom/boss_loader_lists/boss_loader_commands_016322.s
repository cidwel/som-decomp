.setcpu "65816"
.segment "CODE"
.org $6322
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16322:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16327:
    boss_loader_create_descriptor_object $0003
boss_loader_pc_c1632a:
    boss_loader_load_ram_resource_11 $000E
boss_loader_pc_c1632d:
    boss_loader_load_ram_resource_11 $0010
boss_loader_pc_c16330:
    boss_loader_end
