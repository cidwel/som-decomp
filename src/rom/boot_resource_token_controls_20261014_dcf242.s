.setcpu "65816"
.segment "CODE"
.org $F242
control_dcf242:
    ; big-endian decoded byte count
    .byte $20, $00
    ; literal count 1; following payload excluded
    .byte $00
