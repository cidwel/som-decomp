.setcpu "65816"
.segment "CODE"
.org $EE15
control_dcee15:
    ; backreference count 5, distance 32
    .byte $88, $1F
    ; literal count 12; following payload excluded
    .byte $0B
