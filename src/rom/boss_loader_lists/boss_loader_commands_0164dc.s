.setcpu "65816"
.segment "CODE"
.org $64DC
.include "boss_loader_command_macros.inc"
boss_loader_pc_c164dc:
    boss_loader_initialize_graphics_pattern
boss_loader_pc_c164dd:
    boss_loader_create_descriptor_object $0008
boss_loader_pc_c164e0:
    boss_loader_load_indirect_vram_resource $0017
boss_loader_pc_c164e3:
    boss_loader_load_indirect_vram_resource $0026
boss_loader_pc_c164e6:
    boss_loader_load_ram_resource_11 $0016
boss_loader_pc_c164e9:
    boss_loader_load_ram_resource_11 $0025
boss_loader_pc_c164ec:
    boss_loader_end
