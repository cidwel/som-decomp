.setcpu "65816"
.segment "CODE"
.org $C3F6
control_c7c3f6:
    ; backreference count 5, distance 128
    .byte $88, $7F
    ; backreference count 4, distance 192
    .byte $84, $BF
    ; literal count 15; following payload excluded
    .byte $0E
