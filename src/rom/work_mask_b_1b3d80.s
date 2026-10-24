.setcpu "65816"
.segment "RODATA"
.org $3D80
work_mask_b_1b3d80:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
