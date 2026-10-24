.setcpu "65816"
.segment "RODATA"
.org $42F1
work_mask_b_1b42f1:
    .byte (0 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
