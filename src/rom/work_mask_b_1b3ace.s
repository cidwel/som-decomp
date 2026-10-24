.setcpu "65816"
.segment "RODATA"
.org $3ACE
work_mask_b_1b3ace:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
