; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A4BC
boss_lz_controls_dba4bc:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 78; subsequent asset bytes excluded
    .byte $4D
