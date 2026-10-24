.setcpu "65816"
.segment "CODE"
.org $EF72
control_dcef72:
    ; backreference count 13, distance 192
    .byte $A8, $BF
    ; literal count 17; following payload excluded
    .byte $10
