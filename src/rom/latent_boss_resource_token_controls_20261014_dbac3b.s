; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC3B
boss_lz_controls_dbac3b:
    ; backreference count 4, distance 643
    .byte $86, $82
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
