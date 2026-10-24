; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A9F2
boss_lz_controls_dba9f2:
    ; backreference count 3, distance 208
    .byte $80, $CF
    ; literal count 21; subsequent asset bytes excluded
    .byte $14
