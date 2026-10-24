.setcpu "65816"
.segment "RODATA"
.org $DADF
work_mask_b_1bdadf:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
