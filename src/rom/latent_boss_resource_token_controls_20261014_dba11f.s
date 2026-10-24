; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A11F
boss_lz_controls_dba11f:
    ; backreference count 3, distance 120
    .byte $80, $77
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
