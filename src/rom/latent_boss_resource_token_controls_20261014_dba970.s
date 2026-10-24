; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A970
boss_lz_controls_dba970:
    ; backreference count 3, distance 333
    .byte $81, $4C
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
