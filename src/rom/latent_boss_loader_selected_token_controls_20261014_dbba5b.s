; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA5B
boss_lz_controls_dbba5b:
    ; backreference count 3, distance 925
    .byte $83, $9C
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
