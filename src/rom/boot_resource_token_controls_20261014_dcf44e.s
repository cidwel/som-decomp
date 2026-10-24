.setcpu "65816"
.segment "CODE"
.org $F44E
control_dcf44e:
    ; backreference count 16, distance 48
    .byte $8D, $2F
    ; literal count 23; following payload excluded
    .byte $16
