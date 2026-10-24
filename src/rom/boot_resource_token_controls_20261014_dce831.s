.setcpu "65816"
.segment "CODE"
.org $E831
control_dce831:
    ; backreference count 5, distance 2
    .byte $88, $01
    ; backreference count 7, distance 32
    .byte $90, $1F
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 24, distance 1
    .byte $D4, $00
    ; literal count 1; following payload excluded
    .byte $00
