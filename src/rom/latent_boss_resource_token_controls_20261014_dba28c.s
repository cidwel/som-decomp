; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A28C
boss_lz_controls_dba28c:
    ; backreference count 4, distance 106
    .byte $88, $69
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
