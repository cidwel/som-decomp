; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1E3
work_projectile_masks_20261014_final3_01_1be1e3:
    .byte ($80 | $40 | $08 | $04 | $02 | $01)
