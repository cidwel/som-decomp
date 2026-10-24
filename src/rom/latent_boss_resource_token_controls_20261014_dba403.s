; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A403
boss_lz_controls_dba403:
    ; backreference count 4, distance 1777
    .byte $8E, $F0
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
