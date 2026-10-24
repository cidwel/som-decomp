.setcpu "65816"
.segment "CODE"
.org $61BA
.include "boss_loader_command_macros.inc"
boss_loader_pc_c161ba:
    boss_loader_reset_secondary_object_buffers
boss_loader_pc_c161bb:
    boss_loader_write_word $02CB, $651A
boss_loader_pc_c161c0:
    boss_loader_write_word $0FC0, $5000
boss_loader_pc_c161c5:
    boss_loader_write_word $0FC2, $FFFF
boss_loader_pc_c161ca:
    boss_loader_end
boss_loader_pc_c161cb:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c161d0:
    boss_loader_create_descriptor_object $0000
boss_loader_pc_c161d3:
    boss_loader_load_indirect_vram_resource $0007
boss_loader_pc_c161d6:
    boss_loader_load_palette $000E, $000E
boss_loader_pc_c161db:
    boss_loader_end
