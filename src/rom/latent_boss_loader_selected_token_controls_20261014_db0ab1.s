; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AB1
boss_lz_controls_db0ab1:
    ; backreference count 4, distance 951
    .byte $93, $B6
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
