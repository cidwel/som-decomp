.setcpu "65816"
.segment "CODE"
.org $61DF
.include "boss_loader_command_macros.inc"
boss_loader_pc_c161df:
    boss_loader_write_word $0304, $0001
boss_loader_pc_c161e4:
    boss_loader_create_descriptor_object $0000
boss_loader_pc_c161e7:
    boss_loader_load_indirect_vram_resource $0007
boss_loader_pc_c161ea:
    boss_loader_end
