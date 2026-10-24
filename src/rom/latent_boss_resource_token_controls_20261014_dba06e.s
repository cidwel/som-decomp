; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A06E
boss_lz_controls_dba06e:
    ; backreference count 4, distance 1079
    .byte $8C, $36
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
