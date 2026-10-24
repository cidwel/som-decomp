.setcpu "65816"
.segment "CODE"
.org $F267
control_dcf267:
    ; backreference count 10, distance 16
    .byte $87, $0F
    ; literal count 10; following payload excluded
    .byte $09
