; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E271
work_projectile_masks_20261014_final3_01_1be271:
    .byte ($80 | $40)
