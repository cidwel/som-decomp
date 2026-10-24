; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC6D
boss_lz_controls_dbac6d:
    ; backreference count 3, distance 610
    .byte $82, $61
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
