.setcpu "65816"
.segment "CODE"
.org $EE8B
control_dcee8b:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 19; following payload excluded
    .byte $12
