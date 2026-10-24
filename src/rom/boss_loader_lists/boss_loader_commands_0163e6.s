.setcpu "65816"
.segment "CODE"
.org $63E6
.include "boss_loader_command_macros.inc"
boss_loader_pc_c163e6:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c163eb:
    boss_loader_write_word $0FC0, $D000
boss_loader_pc_c163f0:
    boss_loader_create_descriptor_object $0004
boss_loader_pc_c163f3:
    boss_loader_load_ram_resource_11 $0015
boss_loader_pc_c163f6:
    boss_loader_end
