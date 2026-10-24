; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A0A1
boss_lz_controls_dba0a1:
    ; backreference count 3, distance 8
    .byte $80, $07
    ; literal count 25; subsequent asset bytes excluded
    .byte $18
