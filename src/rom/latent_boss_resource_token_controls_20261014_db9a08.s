; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9A08
boss_lz_controls_db9a08:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 21; subsequent asset bytes excluded
    .byte $14
