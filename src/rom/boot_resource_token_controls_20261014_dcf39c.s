.setcpu "65816"
.segment "CODE"
.org $F39C
control_dcf39c:
    ; backreference count 82, distance 256
    .byte $CF, $FF
    ; literal count 14; following payload excluded
    .byte $0D
