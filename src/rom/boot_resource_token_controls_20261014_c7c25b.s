.setcpu "65816"
.segment "CODE"
.org $C25B
control_c7c25b:
    ; backreference count 3, distance 90
    .byte $80, $59
    ; backreference count 4, distance 66
    .byte $84, $41
    ; literal count 1; following payload excluded
    .byte $00
