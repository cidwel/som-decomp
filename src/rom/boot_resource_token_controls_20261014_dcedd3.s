.setcpu "65816"
.segment "CODE"
.org $EDD3
control_dcedd3:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 1; following payload excluded
    .byte $00
