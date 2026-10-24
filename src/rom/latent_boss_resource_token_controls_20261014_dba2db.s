; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2DB
boss_lz_controls_dba2db:
    ; backreference count 4, distance 20
    .byte $88, $13
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
