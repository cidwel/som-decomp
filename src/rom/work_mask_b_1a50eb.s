.setcpu "65816"
.segment "RODATA"
.org $50EB
work_mask_b_1a50eb:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
