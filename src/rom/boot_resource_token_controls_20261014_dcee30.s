.setcpu "65816"
.segment "CODE"
.org $EE30
control_dcee30:
    ; backreference count 5, distance 32
    .byte $88, $1F
    ; literal count 29; following payload excluded
    .byte $1C
