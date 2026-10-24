; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA1E
boss_lz_controls_dbba1e:
    ; backreference count 3, distance 260
    .byte $81, $03
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
