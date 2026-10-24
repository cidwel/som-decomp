.setcpu "65816"
.segment "RODATA"
.org $3C41
work_mask_b_1b3c41:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
