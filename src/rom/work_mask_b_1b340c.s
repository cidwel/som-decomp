.setcpu "65816"
.segment "RODATA"
.org $340C
work_mask_b_1b340c:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
