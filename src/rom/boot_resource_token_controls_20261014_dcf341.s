.setcpu "65816"
.segment "CODE"
.org $F341
control_dcf341:
    ; backreference count 3, distance 18
    .byte $80, $11
    ; literal count 36; following payload excluded
    .byte $23
