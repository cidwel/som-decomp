.setcpu "65816"
.segment "RODATA"
.org $40BF
work_mask_b_1a40bf:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (1 << 0)
