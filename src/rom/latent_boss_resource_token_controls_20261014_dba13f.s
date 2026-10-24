; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A13F
boss_lz_controls_dba13f:
    ; backreference count 4, distance 759
    .byte $8A, $F6
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
