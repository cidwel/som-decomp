; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A9E6
boss_lz_controls_dba9e6:
    ; backreference count 3, distance 433
    .byte $81, $B0
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
