.setcpu "65816"
.segment "CODE"
.org $E869
control_dce869:
    ; backreference count 34, distance 119
    .byte $FC, $76
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 26, distance 1
    .byte $DC, $00
    ; literal count 25; following payload excluded
    .byte $18
