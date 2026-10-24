.setcpu "65816"
.segment "CODE"
.org $C338
control_c7c338:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 1; following payload excluded
    .byte $00
