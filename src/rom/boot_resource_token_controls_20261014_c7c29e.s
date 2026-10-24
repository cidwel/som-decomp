.setcpu "65816"
.segment "CODE"
.org $C29E
control_c7c29e:
    ; backreference count 5, distance 192
    .byte $88, $BF
    ; backreference count 4, distance 2
    .byte $84, $01
    ; literal count 16; following payload excluded
    .byte $0F
