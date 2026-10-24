; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E04A
work_projectile_masks_20261014_final3_00_1be04a:
    .byte ($80 | $08)
