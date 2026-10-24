.setcpu "65816"
.segment "RODATA"
.org $43DD
work_mask_b_1a43dd:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
