; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCF8
boss_lz_controls_dbccf8:
    ; backreference count 4, distance 1454
    .byte $95, $AD
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
