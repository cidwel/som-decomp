.setcpu "65816"
.segment "RODATA"
.org $41DF
work_mask_b_1b41df:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
