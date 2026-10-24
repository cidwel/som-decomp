.setcpu "65816"
.segment "CODE"
.org $C255
control_c7c255:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; backreference count 3, distance 62
    .byte $80, $3D
    ; literal count 1; following payload excluded
    .byte $00
