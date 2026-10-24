.setcpu "65816"
.segment "RODATA"
.org $3D99
work_mask_b_1b3d99:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
