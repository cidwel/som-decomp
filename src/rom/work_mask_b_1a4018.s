.setcpu "65816"
.segment "RODATA"
.org $4018
work_mask_b_1a4018:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
