.setcpu "65816"
.segment "CODE"
.org $6346
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16346:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c16347:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c1634c:
    boss_loader_write_word $02CB, $6567
boss_loader_pc_c16351:
    boss_loader_allocate_and_prepare_object $1811, $7AF4
boss_loader_pc_c16356:
    boss_loader_load_indirect_vram_resource $001C
boss_loader_pc_c16359:
    boss_loader_load_indirect_vram_resource $001D
boss_loader_pc_c1635c:
    boss_loader_end
