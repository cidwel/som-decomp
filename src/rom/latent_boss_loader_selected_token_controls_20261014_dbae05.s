; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE05
boss_lz_controls_dbae05:
    ; backreference count 3, distance 42
    .byte $80, $29
    ; literal count 54; subsequent asset bytes excluded
    .byte $35
