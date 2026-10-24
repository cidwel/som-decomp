.setcpu "65816"
.segment "RODATA"
.org $DDBC
work_mask_b_1bddbc:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
