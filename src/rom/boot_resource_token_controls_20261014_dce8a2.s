.setcpu "65816"
.segment "CODE"
.org $E8A2
control_dce8a2:
    ; backreference count 34, distance 512
    .byte $FD, $FF
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 29, distance 1
    .byte $E8, $00
    ; literal count 4; following payload excluded
    .byte $03
