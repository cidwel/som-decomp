.setcpu "65816"
.segment "CODE"
.org $C40A
control_c7c40a:
    ; backreference count 3, distance 220
    .byte $80, $DB
    ; literal count 3; following payload excluded
    .byte $02
