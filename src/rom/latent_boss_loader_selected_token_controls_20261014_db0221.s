; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0221
boss_lz_controls_db0221:
    ; backreference count 5, distance 8
    .byte $A0, $07
    ; backreference count 4, distance 312
    .byte $91, $37
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
