; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07F6
boss_lz_controls_db07f6:
    ; backreference count 6, distance 7
    .byte $B0, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
