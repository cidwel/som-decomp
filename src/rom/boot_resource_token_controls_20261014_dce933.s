.setcpu "65816"
.segment "CODE"
.org $E933
control_dce933:
    ; backreference count 4, distance 500
    .byte $85, $F3
    ; backreference count 12, distance 2
    .byte $A4, $01
    ; backreference count 34, distance 258
    .byte $FD, $01
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 26, distance 1
    .byte $DC, $00
    ; literal count 16; following payload excluded
    .byte $0F
