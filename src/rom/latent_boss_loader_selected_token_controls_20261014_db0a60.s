; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A60
boss_lz_controls_db0a60:
    ; backreference count 6, distance 7
    .byte $B0, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
