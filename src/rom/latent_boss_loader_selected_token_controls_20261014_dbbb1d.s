; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB1D
boss_lz_controls_dbbb1d:
    ; backreference count 3, distance 169
    .byte $80, $A8
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
