.setcpu "65816"
.segment "CODE"
.org $62E1
.include "boss_loader_command_macros.inc"
boss_loader_pc_c162e1:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c162e6:
    boss_loader_create_descriptor_object $000C
boss_loader_pc_c162e9:
    boss_loader_load_ram_resource_11 $000C
boss_loader_pc_c162ec:
    boss_loader_end
