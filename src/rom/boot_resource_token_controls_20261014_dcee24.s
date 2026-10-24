.setcpu "65816"
.segment "CODE"
.org $EE24
control_dcee24:
    ; backreference count 4, distance 32
    .byte $84, $1F
    ; literal count 1; following payload excluded
    .byte $00
