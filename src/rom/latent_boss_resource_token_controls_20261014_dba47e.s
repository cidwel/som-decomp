; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A47E
boss_lz_controls_dba47e:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
