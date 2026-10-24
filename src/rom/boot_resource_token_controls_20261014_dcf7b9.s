.setcpu "65816"
.segment "CODE"
.org $F7B9
control_dcf7b9:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; backreference count 14, distance 1
    .byte $8B, $00
    ; literal count 48; following payload excluded
    .byte $2F
