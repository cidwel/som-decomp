.setcpu "65816"
.segment "RODATA"
.org $B0BB
DIALOGUE_COMMAND_50 = $50
DIALOGUE_COMMAND_57 = $57
recon_text_called_prefix_controls_20261015_c9b0bb:
    .byte DIALOGUE_COMMAND_50
    .byte DIALOGUE_COMMAND_57
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
