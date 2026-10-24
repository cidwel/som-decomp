.setcpu "65816"
.segment "CODE"
.org $C370
control_c7c370:
    ; backreference count 5, distance 320
    .byte $89, $3F
    ; backreference count 6, distance 448
    .byte $8D, $BF
    ; literal count 1; following payload excluded
    .byte $00
