; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB39
boss_lz_controls_dbcb39:
    ; backreference count 4, distance 243
    .byte $90, $F2
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
