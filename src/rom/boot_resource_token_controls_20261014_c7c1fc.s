.setcpu "65816"
.segment "CODE"
.org $C1FC
control_c7c1fc:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; literal count 5; following payload excluded
    .byte $04
