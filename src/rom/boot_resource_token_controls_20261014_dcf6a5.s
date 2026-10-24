.setcpu "65816"
.segment "CODE"
.org $F6A5
control_dcf6a5:
    ; backreference count 4, distance 18
    .byte $81, $11
    ; backreference count 20, distance 1
    .byte $91, $00
    ; literal count 25; following payload excluded
    .byte $18
