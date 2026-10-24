.setcpu "65816"
.segment "CODE"
.org $63BA
.include "boss_loader_command_macros.inc"
boss_loader_pc_c163ba:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c163bf:
    boss_loader_create_descriptor_object $0007
boss_loader_pc_c163c2:
    boss_loader_load_ram_resource_11 $0013
boss_loader_pc_c163c5:
    boss_loader_load_palette $0058, $000F
boss_loader_pc_c163ca:
    boss_loader_end
