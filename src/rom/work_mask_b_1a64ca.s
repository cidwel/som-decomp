.setcpu "65816"
.segment "RODATA"
.org $64CA
work_mask_b_1a64ca:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
