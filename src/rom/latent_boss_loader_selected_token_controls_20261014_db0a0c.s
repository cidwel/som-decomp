; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A0C
boss_lz_controls_db0a0c:
    ; backreference count 6, distance 2766
    .byte $BA, $CD
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
