.setcpu "65816"
.segment "RODATA"
.org $405C
work_mask_b_1a405c:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
