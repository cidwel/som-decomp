.setcpu "65816"
.segment "RODATA"
.org $DAD7
work_mask_b_1bdad7:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
