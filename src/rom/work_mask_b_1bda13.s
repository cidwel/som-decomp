.setcpu "65816"
.segment "RODATA"
.org $DA13
work_mask_b_1bda13:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
