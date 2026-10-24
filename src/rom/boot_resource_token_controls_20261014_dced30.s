.setcpu "65816"
.segment "CODE"
.org $ED30
control_dced30:
    ; backreference count 3, distance 1024
    .byte $83, $FF
    ; literal count 5; following payload excluded
    .byte $04
