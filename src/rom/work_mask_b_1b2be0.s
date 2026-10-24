.setcpu "65816"
.segment "RODATA"
.org $2BE0
work_mask_b_1b2be0:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
