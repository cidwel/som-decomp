.setcpu "65816"
.segment "RODATA"
.org $3DFF
work_mask_b_1a3dff:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
