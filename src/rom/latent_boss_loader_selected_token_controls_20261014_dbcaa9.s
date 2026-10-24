; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAA9
boss_lz_controls_dbcaa9:
    ; backreference count 3, distance 219
    .byte $80, $DA
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
