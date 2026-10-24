.setcpu "65816"
.segment "CODE"
.org $ED59
control_dced59:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; backreference count 3, distance 1016
    .byte $83, $F7
    ; literal count 12; following payload excluded
    .byte $0B
