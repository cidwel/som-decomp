; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD44
boss_lz_controls_dbcd44:
    ; backreference count 3, distance 693
    .byte $82, $B4
    ; literal count 61; subsequent asset bytes excluded
    .byte $3C
