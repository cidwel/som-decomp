; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A211
boss_lz_controls_dba211:
    ; backreference count 6, distance 805
    .byte $9B, $24
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
