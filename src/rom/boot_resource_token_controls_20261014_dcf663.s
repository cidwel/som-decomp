.setcpu "65816"
.segment "CODE"
.org $F663
control_dcf663:
    ; backreference count 32, distance 123
    .byte $9D, $7A
    ; backreference count 5, distance 1
    .byte $82, $00
    ; literal count 15; following payload excluded
    .byte $0E
