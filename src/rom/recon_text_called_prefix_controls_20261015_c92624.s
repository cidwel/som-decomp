.setcpu "65816"
.segment "RODATA"
.org $2624
DIALOGUE_COMMAND_59 = $59
DIALOGUE_PAGE_END = $7F
recon_text_called_prefix_controls_20261015_c92624:
    .byte DIALOGUE_PAGE_END
    .byte DIALOGUE_COMMAND_59
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
