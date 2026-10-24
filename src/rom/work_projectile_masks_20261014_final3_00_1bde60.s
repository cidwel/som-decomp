; Bits 7..0 select literal (1) or two-item history (0).
; Low-byte controls only; fetched high halves and pixel literals excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE60
work_projectile_masks_20261014_final3_00_1bde60:
    .byte ($80 | $40 | $20 | $10 | $08 | $04 | $02 | $01)
