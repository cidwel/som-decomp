.setcpu "65816"
.segment "CODE"
.org $626F
.include "boss_loader_command_macros.inc"
boss_loader_pc_c1626f:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c16274:
    boss_loader_write_word $02CB, $6567
boss_loader_pc_c16279:
    boss_loader_allocate_and_prepare_object $1811, $44A8
boss_loader_pc_c1627e:
    boss_loader_load_indirect_vram_resource $0000
boss_loader_pc_c16281:
    boss_loader_load_ram_resource_11 $001E
boss_loader_pc_c16284:
    boss_loader_load_ram_resource_11 $0027
boss_loader_pc_c16287:
    boss_loader_load_palette $0022, $000F
boss_loader_pc_c1628c:
    boss_loader_end
