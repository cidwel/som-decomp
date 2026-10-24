; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A363
boss_lz_controls_dba363:
    ; backreference count 3, distance 24
    .byte $80, $17
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
