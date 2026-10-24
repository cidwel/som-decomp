.setcpu "65816"
.segment "CODE"
.org $EE83
control_dcee83:
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 1; following payload excluded
    .byte $00
