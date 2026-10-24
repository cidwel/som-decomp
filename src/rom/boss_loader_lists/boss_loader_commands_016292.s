.setcpu "65816"
.segment "CODE"
.org $6292
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16292:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16297:
    boss_loader_write_word $02CB, $6567
boss_loader_pc_c1629c:
    boss_loader_allocate_and_prepare_object $1811, $44A8
boss_loader_pc_c162a1:
    boss_loader_load_indirect_vram_resource $0000
boss_loader_pc_c162a4:
    boss_loader_load_ram_resource_11 $001E
boss_loader_pc_c162a7:
    boss_loader_load_ram_resource_11 $0027
boss_loader_pc_c162aa:
    boss_loader_load_palette $0025, $000F
boss_loader_pc_c162af:
    boss_loader_end
