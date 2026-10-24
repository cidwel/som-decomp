; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A58
boss_lz_controls_db0a58:
    ; backreference count 4, distance 2671
    .byte $9A, $6E
    ; backreference count 4, distance 2752
    .byte $9A, $BF
    ; backreference count 8, distance 2839
    .byte $DB, $16
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
