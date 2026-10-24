.setcpu "65816"
.segment "CODE"
.org $6334
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16334:
    boss_loader_write_word $0304, $0002
boss_loader_pc_c16339:
    boss_loader_create_descriptor_object $0003
boss_loader_pc_c1633c:
    boss_loader_load_ram_resource_11 $000E
boss_loader_pc_c1633f:
    boss_loader_load_ram_resource_11 $0010
boss_loader_pc_c16342:
    boss_loader_end
