; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C635
boss_lz_controls_dac635:
    ; backreference count 9, distance 519
    .byte $B2, $06
    ; backreference count 3, distance 24
    .byte $80, $17
    ; backreference count 5, distance 516
    .byte $92, $03
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
