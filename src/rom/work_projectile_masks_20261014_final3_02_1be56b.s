; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E56B
work_projectile_masks_20261014_final3_02_1be56b:
    .byte ($00)
    .byte ($80 | $20 | $10 | $08 | $04 | $01)
