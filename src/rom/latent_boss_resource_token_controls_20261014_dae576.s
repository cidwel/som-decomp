; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E576
boss_lz_controls_dae576:
    ; backreference count 15, distance 31
    .byte $E0, $1E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
