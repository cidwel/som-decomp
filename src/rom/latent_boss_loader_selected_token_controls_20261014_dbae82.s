; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE82
boss_lz_controls_dbae82:
    ; backreference count 5, distance 21
    .byte $88, $14
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
