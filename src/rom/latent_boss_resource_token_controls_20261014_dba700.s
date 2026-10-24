; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A700
boss_lz_controls_dba700:
    ; backreference count 3, distance 61
    .byte $80, $3C
    ; literal count 77; subsequent asset bytes excluded
    .byte $4C
