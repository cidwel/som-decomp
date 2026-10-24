.setcpu "65816"
.segment "RODATA"
.org $48CF
work_mask_b_1a48cf:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
