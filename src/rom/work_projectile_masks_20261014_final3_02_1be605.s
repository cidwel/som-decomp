; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E605
work_projectile_masks_20261014_final3_02_1be605:
    .byte ($00)
    .byte ($80 | $40 | $20 | $10 | $08 | $04 | $02)
