.setcpu "65816"
.segment "CODE"
.org $F368
control_dcf368:
    ; backreference count 112, distance 256
    .byte $ED, $FF
    ; literal count 11; following payload excluded
    .byte $0A
