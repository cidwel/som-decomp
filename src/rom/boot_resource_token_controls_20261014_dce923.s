.setcpu "65816"
.segment "CODE"
.org $E923
control_dce923:
    ; backreference count 9, distance 2
    .byte $98, $01
    ; literal count 7; following payload excluded
    .byte $06
