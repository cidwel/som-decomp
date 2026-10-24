.setcpu "65816"
.segment "CODE"
.org $E828
control_dce828:
    ; backreference count 4, distance 3
    .byte $84, $02
    ; backreference count 5, distance 15
    .byte $88, $0E
    ; literal count 4; following payload excluded
    .byte $03
