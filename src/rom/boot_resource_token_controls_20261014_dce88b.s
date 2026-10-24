.setcpu "65816"
.segment "CODE"
.org $E88B
control_dce88b:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 2; following payload excluded
    .byte $01
