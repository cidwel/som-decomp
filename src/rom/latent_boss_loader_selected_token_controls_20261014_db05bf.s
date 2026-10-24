; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05BF
boss_lz_controls_db05bf:
    ; backreference count 5, distance 1648
    .byte $A6, $6F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
