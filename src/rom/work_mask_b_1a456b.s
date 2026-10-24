.setcpu "65816"
.segment "RODATA"
.org $456B
work_mask_b_1a456b:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
