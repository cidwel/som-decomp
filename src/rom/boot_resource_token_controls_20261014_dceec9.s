.setcpu "65816"
.segment "CODE"
.org $EEC9
control_dceec9:
    ; backreference count 3, distance 34
    .byte $80, $21
    ; literal count 19; following payload excluded
    .byte $12
