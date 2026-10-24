.setcpu "65816"
.segment "CODE"
.org $ECF2
control_dcecf2:
    ; backreference count 4, distance 500
    .byte $85, $F3
    ; backreference count 4, distance 282
    .byte $85, $19
    ; literal count 5; following payload excluded
    .byte $04
