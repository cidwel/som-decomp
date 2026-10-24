; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB20
boss_lz_controls_dbcb20:
    ; backreference count 6, distance 231
    .byte $B0, $E6
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
