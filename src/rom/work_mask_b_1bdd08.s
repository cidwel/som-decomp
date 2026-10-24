.setcpu "65816"
.segment "RODATA"
.org $DD08
work_mask_b_1bdd08:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
