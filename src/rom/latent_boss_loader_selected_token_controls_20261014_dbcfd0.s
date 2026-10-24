; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFD0
boss_lz_controls_dbcfd0:
    ; backreference count 3, distance 1734
    .byte $86, $C5
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
