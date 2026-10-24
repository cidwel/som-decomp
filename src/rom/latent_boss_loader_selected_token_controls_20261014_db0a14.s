; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A14
boss_lz_controls_db0a14:
    ; backreference count 7, distance 2724
    .byte $CA, $A3
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
