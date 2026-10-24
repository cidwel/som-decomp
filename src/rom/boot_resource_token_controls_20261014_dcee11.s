.setcpu "65816"
.segment "CODE"
.org $EE11
control_dcee11:
    ; backreference count 3, distance 192
    .byte $80, $BF
    ; literal count 1; following payload excluded
    .byte $00
