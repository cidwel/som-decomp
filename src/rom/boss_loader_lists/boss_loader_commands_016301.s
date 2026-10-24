.setcpu "65816"
.segment "CODE"
.org $6301
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16301:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16306:
    boss_loader_create_descriptor_object $0005
boss_loader_pc_c16309:
    boss_loader_load_ram_resource_11 $000D
boss_loader_pc_c1630c:
    boss_loader_end
