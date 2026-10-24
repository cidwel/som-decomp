; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AF5
boss_lz_controls_db0af5:
    ; backreference count 6, distance 89
    .byte $B0, $58
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
