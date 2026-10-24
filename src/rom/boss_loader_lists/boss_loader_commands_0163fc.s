.setcpu "65816"
.segment "CODE"
.org $63FC
.include "boss_loader_command_macros.inc"
boss_loader_pc_c163fc:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16401:
    boss_loader_write_word $0FC0, $D000
boss_loader_pc_c16406:
    boss_loader_create_descriptor_object $0004
boss_loader_pc_c16409:
    boss_loader_load_ram_resource_11 $0015
boss_loader_pc_c1640c:
    boss_loader_end
