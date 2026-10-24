; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A75C
boss_lz_controls_dba75c:
    ; backreference count 3, distance 92
    .byte $80, $5B
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
