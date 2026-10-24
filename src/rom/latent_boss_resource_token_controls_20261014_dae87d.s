; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E87D
boss_lz_controls_dae87d:
    ; backreference count 3, distance 102
    .byte $80, $65
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
