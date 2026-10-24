.setcpu "65816"
.segment "CODE"
.org $F704
control_dcf704:
    ; backreference count 4, distance 163
    .byte $81, $A2
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 11, distance 1
    .byte $88, $00
    ; literal count 1; following payload excluded
    .byte $00
