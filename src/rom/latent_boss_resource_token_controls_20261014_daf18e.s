; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F18E
boss_lz_controls_daf18e:
    ; backreference count 5, distance 1074
    .byte $A4, $31
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
