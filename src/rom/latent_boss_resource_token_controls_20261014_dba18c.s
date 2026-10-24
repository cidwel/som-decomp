; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A18C
boss_lz_controls_dba18c:
    ; backreference count 3, distance 198
    .byte $80, $C5
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
