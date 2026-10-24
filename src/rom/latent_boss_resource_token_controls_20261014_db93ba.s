; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93BA
boss_lz_controls_db93ba:
    ; backreference count 9, distance 64
    .byte $E0, $3F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
