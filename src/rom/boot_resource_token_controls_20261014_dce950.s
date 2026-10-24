.setcpu "65816"
.segment "CODE"
.org $E950
control_dce950:
    ; backreference count 4, distance 692
    .byte $86, $B3
    ; backreference count 4, distance 184
    .byte $84, $B7
    ; literal count 3; following payload excluded
    .byte $02
