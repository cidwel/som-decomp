; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCB4
boss_lz_controls_dbccb4:
    ; backreference count 4, distance 1464
    .byte $95, $B7
    ; backreference count 3, distance 58
    .byte $80, $39
    ; literal count 63; subsequent asset bytes excluded
    .byte $3E
