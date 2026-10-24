.setcpu "65816"
.segment "CODE"
.org $C485
control_c7c485:
    ; backreference count 5, distance 224
    .byte $88, $DF
    ; backreference count 12, distance 1
    .byte $A4, $00
    ; literal count 1; following payload excluded
    .byte $00
