.setcpu "65816"
.segment "CODE"
.org $E862
control_dce862:
    ; backreference count 12, distance 32
    .byte $A4, $1F
    ; literal count 4; following payload excluded
    .byte $03
