; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB5F
boss_lz_controls_dbcb5f:
    ; backreference count 4, distance 222
    .byte $90, $DD
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
