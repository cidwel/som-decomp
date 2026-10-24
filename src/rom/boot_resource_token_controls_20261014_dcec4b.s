.setcpu "65816"
.segment "CODE"
.org $EC4B
control_dcec4b:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; literal count 17; following payload excluded
    .byte $10
