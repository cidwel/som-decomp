.setcpu "65816"
.segment "RODATA"
.org $3AAD
work_mask_b_1b3aad:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
