; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B7C
boss_lz_controls_db0b7c:
    ; backreference count 4, distance 2077
    .byte $98, $1C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
