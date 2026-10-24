.setcpu "65816"
.segment "CODE"
.org $62D0
.include "boss_loader_command_macros.inc"
boss_loader_pc_c162d0:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c162d5:
    boss_loader_create_descriptor_object $000C
boss_loader_pc_c162d8:
    boss_loader_load_ram_resource_11 $000C
boss_loader_pc_c162db:
    boss_loader_end
