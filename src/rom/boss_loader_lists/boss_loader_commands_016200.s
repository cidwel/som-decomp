.setcpu "65816"
.segment "CODE"
.org $6200
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16200:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c16205:
    boss_loader_allocate_and_prepare_object $1811, $56DB
boss_loader_pc_c1620a:
    boss_loader_load_indirect_vram_resource $0006
boss_loader_pc_c1620d:
    boss_loader_end
