.setcpu "65816"
.segment "CODE"
.org $F7EE
control_dcf7ee:
    ; backreference count 130, distance 226
    .byte $FF, $E1
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 22, distance 1
    .byte $93, $00
