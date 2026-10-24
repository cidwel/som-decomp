.setcpu "65816"
.segment "CODE"
.org $F603
control_dcf603:
    ; backreference count 40, distance 248
    .byte $A5, $F7
    ; literal count 7; following payload excluded
    .byte $06
