.setcpu "65816"
.segment "RODATA"
.org $DAFD
work_mask_b_1bdafd:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
