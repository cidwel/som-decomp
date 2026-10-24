; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2A8
boss_lz_controls_dba2a8:
    ; backreference count 4, distance 45
    .byte $88, $2C
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
