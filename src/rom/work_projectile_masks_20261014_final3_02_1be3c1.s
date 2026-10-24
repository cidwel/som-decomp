; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E3C1
work_projectile_masks_20261014_final3_02_1be3c1:
    .byte ($08 | $04 | $02 | $01)
