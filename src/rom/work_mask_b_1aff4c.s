.setcpu "65816"
.segment "RODATA"
.org $FF4C
work_mask_b_1aff4c:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (0 << 0)
