.setcpu "65816"
.segment "CODE"
.org $ED84
control_dced84:
    ; backreference count 8, distance 472
    .byte $95, $D7
    ; literal count 5; following payload excluded
    .byte $04
