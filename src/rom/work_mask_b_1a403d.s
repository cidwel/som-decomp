.setcpu "65816"
.segment "RODATA"
.org $403D
work_mask_b_1a403d:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
