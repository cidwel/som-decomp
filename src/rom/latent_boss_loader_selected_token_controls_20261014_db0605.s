; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0605
boss_lz_controls_db0605:
    ; backreference count 4, distance 1405
    .byte $95, $7C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
