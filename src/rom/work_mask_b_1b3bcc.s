.setcpu "65816"
.segment "RODATA"
.org $3BCC
work_mask_b_1b3bcc:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
