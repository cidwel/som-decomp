; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0ADC
boss_lz_controls_db0adc:
    ; backreference count 5, distance 76
    .byte $A0, $4B
    ; backreference count 3, distance 726
    .byte $82, $D5
    ; backreference count 4, distance 58
    .byte $90, $39
    ; backreference count 3, distance 7
    .byte $80, $06
    ; backreference count 4, distance 14
    .byte $90, $0D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
