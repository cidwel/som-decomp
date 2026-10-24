; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A321
boss_lz_controls_dba321:
    ; backreference count 3, distance 106
    .byte $80, $69
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
