.setcpu "65816"
.segment "CODE"
.org $EE2C
control_dcee2c:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 1; following payload excluded
    .byte $00
