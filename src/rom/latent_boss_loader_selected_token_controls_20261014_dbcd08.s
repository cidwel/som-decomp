; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD08
boss_lz_controls_dbcd08:
    ; backreference count 4, distance 1458
    .byte $95, $B1
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
