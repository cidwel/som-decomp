.setcpu "65816"
.segment "CODE"
.org $F25A
control_dcf25a:
    ; backreference count 5, distance 14
    .byte $82, $0D
    ; backreference count 27, distance 1
    .byte $98, $00
    ; backreference count 4, distance 52
    .byte $81, $33
    ; literal count 6; following payload excluded
    .byte $05
