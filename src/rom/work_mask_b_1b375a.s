.setcpu "65816"
.segment "RODATA"
.org $375A
work_mask_b_1b375a:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
