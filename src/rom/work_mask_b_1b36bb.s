.setcpu "65816"
.segment "RODATA"
.org $36BB
work_mask_b_1b36bb:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
