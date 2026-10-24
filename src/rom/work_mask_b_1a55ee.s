.setcpu "65816"
.segment "RODATA"
.org $55EE
work_mask_b_1a55ee:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
