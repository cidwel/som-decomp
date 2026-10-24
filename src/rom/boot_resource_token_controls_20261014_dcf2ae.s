.setcpu "65816"
.segment "CODE"
.org $F2AE
control_dcf2ae:
    ; backreference count 6, distance 16
    .byte $83, $0F
    ; backreference count 130, distance 256
    .byte $FF, $FF
    ; backreference count 121, distance 1
    .byte $F6, $00
    ; literal count 16; following payload excluded
    .byte $0F
