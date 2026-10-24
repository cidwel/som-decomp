.setcpu "65816"
.segment "CODE"
.org $C2CD
control_c7c2cd:
    ; backreference count 3, distance 192
    .byte $80, $BF
    ; literal count 1; following payload excluded
    .byte $00
