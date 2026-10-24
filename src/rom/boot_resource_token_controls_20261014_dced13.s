.setcpu "65816"
.segment "CODE"
.org $ED13
control_dced13:
    ; backreference count 3, distance 154
    .byte $80, $99
    ; literal count 5; following payload excluded
    .byte $04
