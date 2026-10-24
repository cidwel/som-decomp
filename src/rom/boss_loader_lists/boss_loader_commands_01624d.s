.setcpu "65816"
.segment "CODE"
.org $624D
.include "boss_loader_command_macros.inc"
boss_loader_pc_c1624d:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16252:
    boss_loader_create_descriptor_object $0001
boss_loader_pc_c16255:
    boss_loader_load_ram_resource_11 $0008
boss_loader_pc_c16258:
    boss_loader_end
