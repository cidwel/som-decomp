.setcpu "65816"
.segment "CODE"
.org $EF3A
control_dcef3a:
    ; backreference count 4, distance 52
    .byte $84, $33
    ; backreference count 4, distance 60
    .byte $84, $3B
    ; literal count 1; following payload excluded
    .byte $00
