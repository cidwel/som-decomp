; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A2F
boss_lz_controls_db0a2f:
    ; backreference count 6, distance 31
    .byte $B0, $1E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
