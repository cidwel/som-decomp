; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $056F
boss_lz_controls_db056f:
    ; backreference count 5, distance 149
    .byte $A0, $94
    ; backreference count 4, distance 318
    .byte $91, $3D
    ; backreference count 3, distance 8
    .byte $80, $07
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
