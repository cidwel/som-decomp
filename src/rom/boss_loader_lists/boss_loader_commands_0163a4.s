.setcpu "65816"
.segment "CODE"
.org $63A4
.include "boss_loader_command_macros.inc"
boss_loader_pc_c163a4:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c163a9:
    boss_loader_create_descriptor_object $0007
boss_loader_pc_c163ac:
    boss_loader_load_ram_resource_11 $0013
boss_loader_pc_c163af:
    boss_loader_load_palette $0058, $000F
boss_loader_pc_c163b4:
    boss_loader_end
