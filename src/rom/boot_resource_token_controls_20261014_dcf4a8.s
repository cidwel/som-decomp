.setcpu "65816"
.segment "CODE"
.org $F4A8
control_dcf4a8:
    ; backreference count 3, distance 190
    .byte $80, $BD
    ; literal count 19; following payload excluded
    .byte $12
