; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE2D
boss_lz_controls_dbce2d:
    ; backreference count 3, distance 2012
    .byte $87, $DB
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
