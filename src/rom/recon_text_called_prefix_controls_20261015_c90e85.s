.setcpu "65816"
.segment "RODATA"
.org $0E85
DIALOGUE_COMMAND_52 = $52
DIALOGUE_COMMAND_57 = $57
recon_text_called_prefix_controls_20261015_c90e85:
    .byte DIALOGUE_COMMAND_52
    .byte DIALOGUE_COMMAND_57
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (1 << 0)
