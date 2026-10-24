.setcpu "65816"
.segment "CODE"
.org $F776
control_dcf776:
    ; backreference count 15, distance 1
    .byte $8C, $00
    ; literal count 9; following payload excluded
    .byte $08
