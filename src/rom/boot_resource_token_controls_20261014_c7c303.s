.setcpu "65816"
.segment "CODE"
.org $C303
control_c7c303:
    ; backreference count 6, distance 224
    .byte $8C, $DF
    ; literal count 1; following payload excluded
    .byte $00
