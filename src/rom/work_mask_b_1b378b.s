.setcpu "65816"
.segment "RODATA"
.org $378B
work_mask_b_1b378b:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
