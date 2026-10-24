; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A1F1
boss_lz_controls_dba1f1:
    ; backreference count 3, distance 37
    .byte $80, $24
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
