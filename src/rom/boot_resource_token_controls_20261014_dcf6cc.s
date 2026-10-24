.setcpu "65816"
.segment "CODE"
.org $F6CC
control_dcf6cc:
    ; backreference count 4, distance 48
    .byte $81, $2F
    ; literal count 35; following payload excluded
    .byte $22
