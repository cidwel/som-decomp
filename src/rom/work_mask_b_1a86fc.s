.setcpu "65816"
.segment "RODATA"
.org $86FC
work_mask_b_1a86fc:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
