; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A086
boss_lz_controls_dba086:
    ; backreference count 4, distance 1081
    .byte $8C, $38
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
