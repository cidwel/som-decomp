; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A55D
boss_lz_controls_dba55d:
    ; backreference count 3, distance 139
    .byte $80, $8A
    ; literal count 43; subsequent asset bytes excluded
    .byte $2A
