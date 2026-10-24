.setcpu "65816"
.segment "CODE"
.org $6364
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16364:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c16365:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c1636a:
    boss_loader_write_word $02CB, $6567
boss_loader_pc_c1636f:
    boss_loader_allocate_and_prepare_object $1811, $7AF4
boss_loader_pc_c16374:
    boss_loader_load_indirect_vram_resource $001C
boss_loader_pc_c16377:
    boss_loader_load_indirect_vram_resource $001D
boss_loader_pc_c1637a:
    boss_loader_end
