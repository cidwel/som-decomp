.setcpu "65816"
.segment "CODE"
.org $F011
control_dcf011:
    ; backreference count 3, distance 871
    .byte $83, $66
    ; backreference count 8, distance 1
    .byte $94, $00
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 1; following payload excluded
    .byte $00
