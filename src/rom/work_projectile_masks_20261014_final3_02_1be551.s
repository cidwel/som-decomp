; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E551
work_projectile_masks_20261014_final3_02_1be551:
    .byte ($08 | $02 | $01)
