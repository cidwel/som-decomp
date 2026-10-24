.setcpu "65816"
.segment "CODE"
.org $EF44
control_dcef44:
    ; backreference count 3, distance 162
    .byte $80, $A1
    ; literal count 16; following payload excluded
    .byte $0F
