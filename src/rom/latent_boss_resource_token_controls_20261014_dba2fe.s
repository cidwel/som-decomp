; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2FE
boss_lz_controls_dba2fe:
    ; backreference count 3, distance 228
    .byte $80, $E3
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
