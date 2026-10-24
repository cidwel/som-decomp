; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E497
boss_lz_controls_dae497:
    ; backreference count 3, distance 500
    .byte $81, $F3
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
