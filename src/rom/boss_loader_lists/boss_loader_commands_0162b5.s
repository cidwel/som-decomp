.setcpu "65816"
.segment "CODE"
.org $62B5
.include "boss_loader_command_macros.inc"
boss_loader_pc_c162b5:
    boss_loader_end
boss_loader_pc_c162b6:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c162b7:
    boss_loader_create_descriptor_object $000E
boss_loader_pc_c162ba:
    boss_loader_write_word $0FC0, $0000
boss_loader_pc_c162bf:
    boss_loader_write_word $0FC2, $0000
boss_loader_pc_c162c4:
    boss_loader_load_indirect_vram_resource $0009
boss_loader_pc_c162c7:
    boss_loader_load_indirect_vram_resource $000A
boss_loader_pc_c162ca:
    boss_loader_end
