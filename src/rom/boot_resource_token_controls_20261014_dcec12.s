.setcpu "65816"
.segment "CODE"
.org $EC12
control_dcec12:
    ; backreference count 3, distance 222
    .byte $80, $DD
    ; backreference count 6, distance 2
    .byte $8C, $01
    ; backreference count 4, distance 404
    .byte $85, $93
    ; backreference count 6, distance 510
    .byte $8D, $FD
    ; backreference count 6, distance 2
    .byte $8C, $01
    ; literal count 11; following payload excluded
    .byte $0A
