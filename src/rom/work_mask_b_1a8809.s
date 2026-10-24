.setcpu "65816"
.segment "RODATA"
.org $8809
work_mask_b_1a8809:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
