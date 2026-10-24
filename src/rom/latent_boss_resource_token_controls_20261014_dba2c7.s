; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2C7
boss_lz_controls_dba2c7:
    ; backreference count 3, distance 249
    .byte $80, $F8
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
