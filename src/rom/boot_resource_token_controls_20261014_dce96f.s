.setcpu "65816"
.segment "CODE"
.org $E96F
control_dce96f:
    ; backreference count 4, distance 24
    .byte $84, $17
    ; literal count 37; following payload excluded
    .byte $24
