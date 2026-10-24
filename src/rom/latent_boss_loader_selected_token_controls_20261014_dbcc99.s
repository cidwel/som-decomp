; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC99
boss_lz_controls_dbcc99:
    ; backreference count 3, distance 1464
    .byte $85, $B7
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
