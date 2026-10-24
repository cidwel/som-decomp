; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D86F
boss_lz_controls_dad86f:
    ; backreference count 7, distance 62
    .byte $A0, $3D
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
