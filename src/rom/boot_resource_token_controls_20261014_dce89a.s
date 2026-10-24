.setcpu "65816"
.segment "CODE"
.org $E89A
control_dce89a:
    ; backreference count 3, distance 515
    .byte $82, $02
    ; backreference count 6, distance 502
    .byte $8D, $F5
    ; backreference count 8, distance 2
    .byte $94, $01
    ; literal count 1; following payload excluded
    .byte $00
