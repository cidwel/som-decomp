.setcpu "65816"
.segment "CODE"
.org $64F4
.include "boss_loader_command_macros.inc"
boss_loader_pc_c164f4:
    boss_loader_end
boss_loader_pc_c164f5:
    boss_loader_write_word $02CB, $6601
boss_loader_pc_c164fa:
    boss_loader_allocate_and_prepare_object $180D, $8F33
boss_loader_pc_c164ff:
    boss_loader_fill_graphics_buffers
boss_loader_pc_c16500:
    boss_loader_call_native_callback $8F20
boss_loader_pc_c16503:
    boss_loader_load_indirect_vram_resource $0024
boss_loader_pc_c16506:
    boss_loader_load_palette $0082, $000D
boss_loader_pc_c1650b:
    boss_loader_load_palette $0083, $000E
boss_loader_pc_c16510:
    boss_loader_end
