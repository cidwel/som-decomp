.setcpu "65816"
.segment "CODE"
.org $6479
.include "boss_loader_command_macros.inc"
boss_loader_pc_c16479:
    boss_loader_write_word $0304, $0000
boss_loader_pc_c1647e:
    boss_loader_write_word $02CB, $65B4
boss_loader_pc_c16483:
    boss_loader_create_descriptor_object $0009
boss_loader_pc_c16486:
    boss_loader_load_direct_vram_resource $0021
boss_loader_pc_c16489:
    boss_loader_load_ram_resource_11 $0022
boss_loader_pc_c1648c:
    boss_loader_load_palette $0038, $000F
boss_loader_pc_c16491:
    boss_loader_end
