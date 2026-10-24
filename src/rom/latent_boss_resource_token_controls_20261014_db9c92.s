; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9C92
boss_lz_controls_db9c92:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
