.setcpu "65816"
.segment "CODE"
.org $F029
control_dcf029:
    ; backreference count 5, distance 8
    .byte $88, $07
    ; backreference count 3, distance 2
    .byte $80, $01
    ; backreference count 10, distance 8
    .byte $9C, $07
