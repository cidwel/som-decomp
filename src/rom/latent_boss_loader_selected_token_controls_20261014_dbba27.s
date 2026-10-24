; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA27
boss_lz_controls_dbba27:
    ; backreference count 3, distance 630
    .byte $82, $75
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
