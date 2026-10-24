.setcpu "65816"
.segment "RODATA"
.org $BF35
DIALOGUE_COMMAND_57 = $57
DIALOGUE_PAGE_END = $7F
recon_text_called_prefix_controls_20261015_c9bf35:
    .byte DIALOGUE_PAGE_END
    .byte DIALOGUE_COMMAND_57
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
