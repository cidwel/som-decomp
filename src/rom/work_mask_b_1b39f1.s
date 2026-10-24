.setcpu "65816"
.segment "RODATA"
.org $39F1
work_mask_b_1b39f1:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
