; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3B7
boss_lz_controls_dba3b7:
    ; backreference count 3, distance 696
    .byte $82, $B7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
