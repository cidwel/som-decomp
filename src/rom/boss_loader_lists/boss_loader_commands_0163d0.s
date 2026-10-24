.setcpu "65816"
.segment "CODE"
.org $63D0
.include "boss_loader_command_macros.inc"
boss_loader_pc_c163d0:
    boss_loader_write_word $0304, $0002
boss_loader_pc_c163d5:
    boss_loader_create_descriptor_object $0007
boss_loader_pc_c163d8:
    boss_loader_load_ram_resource_11 $0013
boss_loader_pc_c163db:
    boss_loader_load_palette $0058, $000F
boss_loader_pc_c163e0:
    boss_loader_end
