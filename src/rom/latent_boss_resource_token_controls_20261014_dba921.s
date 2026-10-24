; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A921
boss_lz_controls_dba921:
    ; backreference count 4, distance 121
    .byte $84, $78
    ; literal count 25; subsequent asset bytes excluded
    .byte $18
