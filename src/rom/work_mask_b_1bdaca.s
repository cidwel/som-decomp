.setcpu "65816"
.segment "RODATA"
.org $DACA
work_mask_b_1bdaca:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
