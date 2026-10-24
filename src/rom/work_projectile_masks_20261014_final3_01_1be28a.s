; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E28A
work_projectile_masks_20261014_final3_01_1be28a:
    .byte ($80 | $40 | $20 | $10 | $08 | $04 | $02)
