; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D1EB
boss_lz_controls_dbd1eb:
    ; backreference count 3, distance 444
    .byte $81, $BB
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
