.setcpu "65816"
.segment "RODATA"
.org $FF65
work_mask_b_1aff65:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
