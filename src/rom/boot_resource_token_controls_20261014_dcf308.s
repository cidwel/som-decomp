.setcpu "65816"
.segment "CODE"
.org $F308
control_dcf308:
    ; backreference count 48, distance 240
    .byte $AD, $EF
    ; backreference count 112, distance 256
    .byte $ED, $FF
    ; backreference count 20, distance 1
    .byte $91, $00
    ; literal count 12; following payload excluded
    .byte $0B
