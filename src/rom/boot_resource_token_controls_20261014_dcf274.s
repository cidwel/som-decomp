.setcpu "65816"
.segment "CODE"
.org $F274
control_dcf274:
    ; backreference count 32, distance 62
    .byte $9D, $3D
    ; backreference count 6, distance 48
    .byte $83, $2F
    ; backreference count 130, distance 1
    .byte $FF, $00
    ; backreference count 26, distance 1
    .byte $97, $00
    ; literal count 16; following payload excluded
    .byte $0F
