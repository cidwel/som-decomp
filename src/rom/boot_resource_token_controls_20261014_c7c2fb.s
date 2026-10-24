.setcpu "65816"
.segment "CODE"
.org $C2FB
control_c7c2fb:
    ; backreference count 3, distance 190
    .byte $80, $BD
    ; backreference count 3, distance 219
    .byte $80, $DA
    ; literal count 3; following payload excluded
    .byte $02
