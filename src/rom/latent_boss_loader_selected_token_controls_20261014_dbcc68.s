; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC68
boss_lz_controls_dbcc68:
    ; backreference count 3, distance 42
    .byte $80, $29
    ; literal count 46; subsequent asset bytes excluded
    .byte $2D
