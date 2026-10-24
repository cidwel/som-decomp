; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9BDB
boss_lz_controls_db9bdb:
    ; backreference count 5, distance 99
    .byte $90, $62
    ; literal count 59; subsequent asset bytes excluded
    .byte $3A
