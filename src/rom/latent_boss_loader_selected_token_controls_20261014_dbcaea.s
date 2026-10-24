; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAEA
boss_lz_controls_dbcaea:
    ; backreference count 3, distance 118
    .byte $80, $75
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
