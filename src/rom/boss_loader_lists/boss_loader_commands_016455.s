.setcpu "65816"
.segment "CODE"
.org $6455
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16455:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c1645a:
    boss_loader_write_word $02CB, $6601
boss_loader_pc_c1645f:
    boss_loader_allocate_and_prepare_object $9C11, $8455
boss_loader_pc_c16464:
    boss_loader_fill_graphics_buffers
boss_loader_pc_c16465:
    boss_loader_load_indirect_vram_high_resource $001A
boss_loader_pc_c16468:
    boss_loader_load_ram_resource_11 $001B
boss_loader_pc_c1646b:
    boss_loader_load_ram_resource_11 $0023
boss_loader_pc_c1646e:
    boss_loader_load_palette $007E, $000E
boss_loader_pc_c16473:
    boss_loader_end
