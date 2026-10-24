; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E0D7
boss_lz_controls_dae0d7:
    ; backreference count 3, distance 92
    .byte $80, $5B
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
