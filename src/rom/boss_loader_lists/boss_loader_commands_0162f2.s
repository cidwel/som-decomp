.setcpu "65816"
.segment "CODE"
.org $62F2
.include "boss_loader_command_macros.inc"
boss_loader_pc_c162f2:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c162f7:
    boss_loader_create_descriptor_object $0005
boss_loader_pc_c162fa:
    boss_loader_load_ram_resource_11 $000D
boss_loader_pc_c162fd:
    boss_loader_end
