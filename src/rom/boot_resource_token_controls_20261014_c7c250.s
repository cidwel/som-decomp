.setcpu "65816"
.segment "CODE"
.org $C250
control_c7c250:
    ; backreference count 4, distance 66
    .byte $84, $41
    ; literal count 2; following payload excluded
    .byte $01
