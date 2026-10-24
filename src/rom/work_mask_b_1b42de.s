.setcpu "65816"
.segment "RODATA"
.org $42DE
work_mask_b_1b42de:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
