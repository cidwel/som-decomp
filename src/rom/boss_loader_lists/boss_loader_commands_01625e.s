.setcpu "65816"
.segment "CODE"
.org $625E
.include "boss_loader_command_macros.inc"
boss_loader_pc_c1625e:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16263:
    boss_loader_create_descriptor_object $0001
boss_loader_pc_c16266:
    boss_loader_load_ram_resource_11 $0008
boss_loader_pc_c16269:
    boss_loader_end
