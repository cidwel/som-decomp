.setcpu "65816"
.segment "CODE"
.org $F376
control_dcf376:
    ; backreference count 5, distance 16
    .byte $82, $0F
    ; literal count 15; following payload excluded
    .byte $0E
