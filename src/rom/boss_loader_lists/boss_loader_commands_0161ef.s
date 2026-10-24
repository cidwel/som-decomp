.setcpu "65816"
.segment "CODE"
.org $61EF
.include "boss_loader_command_macros.inc"
boss_loader_pc_c161ef:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c161f4:
    boss_loader_allocate_and_prepare_object $1811, $56DB
boss_loader_pc_c161f9:
    boss_loader_load_indirect_vram_resource $0006
boss_loader_pc_c161fc:
    boss_loader_end
