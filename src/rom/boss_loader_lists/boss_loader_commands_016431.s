.setcpu "65816"
.segment "CODE"
.org $6431
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16431:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16436:
    boss_loader_write_word $02CB, $6601
boss_loader_pc_c1643b:
    boss_loader_allocate_and_prepare_object $9C11, $8455
boss_loader_pc_c16440:
    boss_loader_fill_graphics_buffers
boss_loader_pc_c16441:
    boss_loader_load_indirect_vram_high_resource $001A
boss_loader_pc_c16444:
    boss_loader_load_ram_resource_11 $001B
boss_loader_pc_c16447:
    boss_loader_load_ram_resource_11 $0023
boss_loader_pc_c1644a:
    boss_loader_load_palette $007E, $000E
boss_loader_pc_c1644f:
    boss_loader_end
