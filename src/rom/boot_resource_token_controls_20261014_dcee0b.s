.setcpu "65816"
.segment "CODE"
.org $EE0B
control_dcee0b:
    ; backreference count 4, distance 32
    .byte $84, $1F
    ; backreference count 6, distance 502
    .byte $8D, $F5
    ; literal count 1; following payload excluded
    .byte $00
