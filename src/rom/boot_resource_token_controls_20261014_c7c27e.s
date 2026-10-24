.setcpu "65816"
.segment "CODE"
.org $C27E
control_c7c27e:
    ; backreference count 4, distance 128
    .byte $84, $7F
    ; literal count 1; following payload excluded
    .byte $00
