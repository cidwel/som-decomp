.setcpu "65816"
.segment "RODATA"
.org $41EA
work_mask_b_1a41ea:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
