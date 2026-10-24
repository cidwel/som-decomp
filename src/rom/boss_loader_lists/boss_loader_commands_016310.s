.setcpu "65816"
.segment "CODE"
.org $6310
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16310:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16315:
    boss_loader_create_descriptor_object $0003
boss_loader_pc_c16318:
    boss_loader_load_ram_resource_11 $000E
boss_loader_pc_c1631b:
    boss_loader_load_ram_resource_11 $000F
boss_loader_pc_c1631e:
    boss_loader_end
