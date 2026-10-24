.setcpu "65816"
.segment "RODATA"
.org $4F70
work_mask_b_1a4f70:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
